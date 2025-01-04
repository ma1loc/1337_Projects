void ft_exec(t_cmds *cmd)
{
    int pip[2];
    int in_file, out_file;
    int pid;

    // Open the input and output files
    in_file = open(cmd->cmd[0], O_RDONLY);
    out_file = open(cmd->next->cmd[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (in_file == -1 || out_file == -1)
    {
        perror("Error opening files");
        return;
    }

    // Create the pipe
    pipe(pip);

    // Fork the first process (ls)
    pid = fork();
    if (pid == 0)  // Child process
    {
        dup2(in_file, 0);  // Input redirection
        dup2(pip[1], 1);   // Output redirection to the pipe
        close(pip[0]);
        execve(cmd->cmd[0], cmd->cmd, NULL);
        exit(1);
    }

    // Fork the second process (grep infile)
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

