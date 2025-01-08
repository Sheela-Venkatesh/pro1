#ifndef USART_H
#define USART_H

typedef struct
{
    unsigned int SR;
    unsigned int DR;
    unsigned int BRR;
    unsigned int CR1;
    unsigned int CR2;
    unsigned int CR3;
} UART_DATA;

#define UARTMAC ((volatile unsigned int) 0x40013800)
#define UARTPTR ((volatile UART_DATA*) UARTMAC)

int my_strcmp(const char *str1, const char *str2);
void usart1_parse_cmd(char *cmd);
char uart_receive(void);
void usart1_receive_cmd();
void uart_send_line(const char *line);
void serial_puts(const char *str);

#endif
