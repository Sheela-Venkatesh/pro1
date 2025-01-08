#include "Rcc.h"

void sys_clock_config()
{
    RCCPTR->CR |= (1 << 0);               
    while (!(RCCPTR->CR & (1 << 1)));
    RCCPTR->CFGR &= ~0x3;
    RCCPTR->CFGR |= 0x0;
}

void enable_uart1_clock()
{
    RCCPTR->APB2ENR |= (1 << 14);
}
