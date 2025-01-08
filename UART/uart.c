#include "usart.h"
#include "gpio.h"

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 1; 
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0')
    {
        return 0;
    }
    return 1;
}

void usart1_parse_cmd(char *cmd)
{
    char str[8] = {0};
    char str2[8] = {0};
    int i = 0, j = 0;

    // Extract command (up to space or end of string)
    while (cmd[i] != ' ' && cmd[i] != '\0' && i < 7) 
    {
        str[i] = (cmd[i] >= 'A' && cmd[i] <= 'Z') ? (cmd[i] + 32) : cmd[i]; // Convert to lowercase
        i++;
    }
    str[i] = '\0';

    if (cmd[i] == ' ')            // Skip space
    {       
        i++;
    }

    // Extract subcommand (rest of the string)
    while (cmd[i] != '\0' && j < 7) 
    {
        str2[j] = (cmd[i] >= 'A' && cmd[i] <= 'Z') ? (cmd[i] + 32) : cmd[i]; // Convert to lowercase
        i++;
        j++;
    }
    str2[j] = '\0';

    if (my_strcmp(str, "led") == 0) 
    {
        if (my_strcmp(str2, "on") == 0) 
        {
            led_on();  // Turn on the LED
            serial_puts("\r\nLED IS ON\r\n");
        } 
        else if (my_strcmp(str2, "off") == 0) 
        {
            led_off();  // Turn off the LED
            serial_puts("\r\nLED IS OFF\r\n");
        } 
        else 
        {
            serial_puts("\r\nInvalid LED subcommand! Use 'ON' or 'OFF'.\r\n");
        }
    } 
    else 
    {
        serial_puts("\r\nUnknown command! Use 'LED'.\r\n");
    }
}

char uart_receive(void)
{
    while (!(UARTPTR->SR & (1 << 5)));    
    return (char)(UARTPTR->DR);
}

void usart1_receive_cmd()
{
    char cmd[5] = {0}; 
    int index = 0;

    while (1)
    {
        char received_char = uart_receive(); 
        if (received_char == '\r' || received_char == '\n')
        {
            cmd[index] = '\0';
            usart1_parse_cmd(cmd);  
            index = 0;   
        }
        else if (index < 4)
        {
            cmd[index++] = received_char;  
        }
    }
}

void app_uart_put(char c) {
    while (!(UARTPTR->SR & (1 << 7)));        // Wait for UART TX buffer to be empty
    UARTPTR->DR = c;                          // Send the character
}

void uart_send_line(const char *line) 
{
    // Implementation for sending a string over UART
    while (*line) 
    {
        while (!(UARTPTR->SR & (1 << 7)));   // Wait for TX buffer
        UARTPTR->DR = *line++;               // Send the character
    }
}

void serial_puts(const char *str) 
{
    while (*str) 
    {
        app_uart_put(*str++);  // Use your UART sending function to send each character
    }
}
