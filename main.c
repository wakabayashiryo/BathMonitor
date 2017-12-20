/*
 * File:   main.c
 * Author: evaota
 *
 * Created on 2017/12/15, 14:24
 */
#include "main.h"

void main(void) 
{
    Basic_Init();
    UART_Init(UART_InitPort,BAUD_9600);
    
    
    while(1)
    {
        printf("Hello World\n");
    }
}

void interrupt Handle(void)
{
    UART_Interrupt();
//    I2C_Interrupt();
}

void Basic_Init(void)
{
    TRISA = 0x00;
    
    ANSELA = 0x00;
    
    APFCON = 0x00;
    
    PORTA = 0x00;
}

void UART_InitPort(void)
{
    TRISA &= ~(1<<4);
    APFCON |= (1<<4);
    ANSELA &= ~(1<<4);
}

