#include "Rcc.h"
#include "gpio.h"
#include "usart.h"
#include "cli.h"

int main()
{
    sys_clock_config();                    
    enable_uart1_clock();                  
    gpio_config_uart();  
    gpio_led_config();	
    usart1_receive_cmd(); 
    return 0;
}
