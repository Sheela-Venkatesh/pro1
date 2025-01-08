#ifndef RCC_H
#define RCC_H

typedef struct
{
    unsigned int CR;
    unsigned int CFGR;
    unsigned int CIR;
    unsigned int APB2RSTR;
    unsigned int APB1RSTR;
    unsigned int AHBENR;
    unsigned int APB2ENR;
    unsigned int APB1ENR;
    unsigned int CSR;
    unsigned int AHBRSTR;
} RCC_DATA;

#define RCCMAC ((volatile unsigned int) 0x40021000)
#define RCCPTR ((volatile RCC_DATA*) RCCMAC)

void sys_clock_config();
void enable_uart1_clock();

#endif
