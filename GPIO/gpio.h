#ifndef GPIO_H
#define GPIO_H

typedef struct
{
    unsigned int CRL;
    unsigned int CRH;
    unsigned int IDR;
    unsigned int ODR;
    unsigned int BSRR;
    unsigned int BRR;
} GPIO_DATA;

#define GPIOMAC ((volatile unsigned int) 0x40010800)
#define GPIOPTR ((volatile GPIO_DATA*) GPIOMAC)

void gpio_config_uart();
void gpio_led_config();
void led_on();
void led_off();

#endif
