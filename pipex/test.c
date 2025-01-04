typedef struct pipex
{
    char **cmd;
    struct pipex *next;
} t_cmds;

void ft_exec(t_cmds *cmd)
{
    int pip[2];       // Pipe to connect output of one command to input of the next
    int in_put = 0;   // Input for the first command (initially stdin)
    int i = 0;

    while (cmd)
    {
        if (cmd->next)  // If there's a next command, create a pipe
        {
            if (pipe(pip) == -1)
            {
                perror("pipe");
                exit(1);
            }
        }

        int pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }

        if (pid == 0)  // Child process
        {
            // Redirect input if it's not the first command
            if (in_put != 0 && dup2(in_put, 0) == -1)
            {
                perror("dup2 input");
                exit(1);
            }

            // Redirect output if it's not the last command
            if (cmd->next && dup2(pip[1], 1) == -1)
            {
                perror("dup2 output");
                exit(1);
            }

            // Close unused file descriptors in the child
            close(pip[0]);
            close(pip[1]);

            // Execute the command
            execve(cmd->cmd[0], cmd->cmd, NULL);

            // If execve fails
            perror("execve");
            exit(1);
        }
        
        // Parent process
        // Close the write end of the pipe in the parent process
        close(pip[1]);

        // Close the previous input pipe if it's not the first command
        if (i != 0)
        {
            close(in_put);
        }

        // Update the input for the next command
        in_put = pip[0];
        cmd = cmd->next;
        i++;
    }

    // Wait for all child processes to finish
    while (cmd)
    {
        wait(NULL);
        cmd = cmd->next;
    }
}

