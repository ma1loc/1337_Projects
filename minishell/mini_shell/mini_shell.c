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
            input = readline("\nminishell$ ");
            if (input == NULL)
            {
                printf("minishell exit done\n");
                break;
            }
            if (*input)
                add_history(input);
            // >>> parsing will start here.
            echo_msg(input);
            free(input);
            // free(input);  // Free the allocated memory for input
        }
    }
    else
    {
        printf("execute minishell without any argc\n");
        exit(1);
    }
    return 0;
}
