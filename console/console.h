#ifndef CONSOLE_H
#define CONSOLE_H

void console_read_input(void);  // To read input and process the command
char uart_receive(void);        // Function to receive a character from UART
void uart_send_line(const char *line);  // Function to send a line over UART

#endif // CONSOLE_H
