#include "cli.h"
#include <string.h>
#include "gpio.h"  
#include "console.h" 

#define BUFFER_SIZE 16

char buff[BUFFER_SIZE];  // Input buffer
unsigned short int index = 0;

// Process input from UART and execute commands
void console_read_input(void) 
	{
    unsigned char data = uart_receive();
    uart_send_line((const char *)&data);  
    if (data == '\n' || data == '\r') 
			{  
        buff[index] = '\0';  
        parse_cmd(buff);  
        memset(buff, '\0', sizeof(buff));  
        index = 0;  
      } 
		else 
		{
        if (index < BUFFER_SIZE - 1) 
					{
            buff[index++] = data;  
          } 
				else 
						{
            uart_send_line("\r\nBuffer full, clearing...\r\n");
            memset(buff, '\0', sizeof(buff)); 
            index = 0; 
            }
    }
}
