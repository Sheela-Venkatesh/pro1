#ifndef CLI_H
#define CLI_H

#include <stddef.h>

// Command structure definition
typedef struct ShellCommand {
    const char *command;
    int (*handler)(int argc, char *argv[]);
    const char *help;
} sShellCommand;

extern const sShellCommand *const g_shell_commands;
extern const size_t g_num_shell_commands;

// CLI functions
extern void shell_put_line(const char *line); // Declare function
void parse_cmd(char *cmd);
void app_uart_put(char c);
void uart_send_line(const char *line);

#endif // CLI_H
