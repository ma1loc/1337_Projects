#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

typedef struct pipex
{
    char **cmd;
    struct pipex *next;
} t_cmds;

void    ft_error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

t_cmds  *ft_newcmd(char **cmd)
{
    t_cmds *new = malloc(sizeof(t_cmds));
    if (!new)
        ft_error("malloc");
    new->cmd = cmd;
    new->next = NULL;
    return new;
}

void    ft_addcmd(t_cmds **cmds, char **cmd)
{
    t_cmds *new = ft_newcmd(cmd);
    t_cmds *temp = *cmds;
    
    if (*cmds == NULL)
    {
        *cmds = new;
    }
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}

void    ft_exec(t_cmds *cmd)
{
    int pip[2];
    int in_file, out_file;
    int pid;

    // Open the input and output files
    in_file = open(cmd->cmd[0], O_RDONLY);
    if (in_file == -1)
        ft_error("Error opening input file");

    out_file = open(cmd->next->cmd[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_file == -1)
        ft_error("Error opening output file");

    // Create the pipe
    pipe(pip);

    // Fork the first process (e.g., ls)
    pid = fork();
    if (pid == 0)  // Child process
    {
        dup2(in_file, 0);  // Input redirection
        dup2(pip[1], 1);   // Output redirection to the pipe
        close(pip[0]);
        execve(cmd->cmd[0], cmd->cmd, NULL);
        exit(1);
    }

    // Fork the second process (e.g., grep)
    pid = fork();
    if (pid == 0)  // Child process
    {
        dup2(pip[0], 0);  // Input redirection from the pipe
        dup2(out_file, 1); // Output redirection to the output file
        close(pip[1]);
        execve(cmd->next->cmd[0], cmd->next->cmd, NULL);
        exit(1);
    }

    // Parent process
    close(pip[0]);
    close(pip[1]);
    close(in_file);
    close(out_file);

    // Wait for child processes to finish
    wait(NULL);
    wait(NULL);
}

int main(int argc, char *argv[])
{
    t_cmds *cmds = NULL;

    if (argc < 5)
    {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
        return 1;
    }

    // Create the command list
    char *cmd1[] = {argv[2], NULL};
    char *cmd2[] = {argv[3], NULL};
    
    ft_addcmd(&cmds, cmd1);
    ft_addcmd(&cmds, cmd2);

    // Execute the pipeline
    ft_exec(cmds);

    return 0;
}

