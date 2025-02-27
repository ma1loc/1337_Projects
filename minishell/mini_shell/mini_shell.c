#include "mini_shell.h"

// cc cc.c -lreadline -o a.out
int main(int argc, char **argv)
{
    char *input;
    argv[1] = NULL;
    if (argc == 1)
    {
        while (1)
        {
            input = readline("minishell$ ");
            if (input == NULL)
            {
                printf("minishell exit done\n");
                break;
            }
            if (*input)
                add_history(input);
            // >>> parsing
                // will start here.
                // just to take an image.
            // <<<

            // >>> test the execution.
            echo_msg(input, "-n");
            free(input);
        }
    }
    else
    {
        printf("execute minishell without any argc\n");
        exit(1);
    }
    return 0;
}
