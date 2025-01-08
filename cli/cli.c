#include "cli.h"
#include <string.h>

void shell_put_line(const char *line) 
{
    while (*line) 
    {
        app_uart_put(*line++);
    }
    app_uart_put('\n');
}

// Example command handler
int cli_cmd_hello(int argc, char *argv[]) 
{
    shell_put_line("Hello World!");
    return 0;
}

// Command list
static const sShellCommand s_shell_commands[] = {{"HELLO", cli_cmd_hello, "Prints Hello World!"}};

const sShellCommand *const g_shell_commands = s_shell_commands;
const size_t g_num_shell_commands = sizeof(s_shell_commands) / sizeof(s_shell_commands[0]);

// Parses the received command string
void parse_cmd(char *cmd) 
{
    int argc = 0;
    char *argv[5] = {0};
    char *token = strtok(cmd, " ");

    while (token && argc < 5) 
    {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    for (size_t i = 0; i < g_num_shell_commands; i++) 
    {
        if (strcmp(argv[0], g_shell_commands[i].command) == 0) 
        {
            g_shell_commands[i].handler(argc, argv);
            return;
        }
    }
    shell_put_line("Unknown command!");
}
