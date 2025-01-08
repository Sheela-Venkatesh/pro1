#include "gpio.h"

void gpio_config_uart()
{
    GPIOPTR->CRH &= ~(0xF0);    // TX
    GPIOPTR->CRH |= (0xB0);
    
    GPIOPTR->CRH &= ~(0xF00);   // RX
    GPIOPTR->CRH |= (0x400);
}

void gpio_led_config()
{
    GPIOPTR->CRL &= ~(0xF0);
    GPIOPTR->CRL |= (0x30);
}

void led_on()
{
    GPIOPTR->ODR |= (1 << 1);
}

void led_off()
{
    GPIOPTR->ODR &= ~(1 << 1);
}
