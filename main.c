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
    
    I2C1_Init(I2C_InitPort,0x00,I2C_MODE_MASTER,I2C_SPEED_HIGH);
    
    uint8_t testdata[13] = "Wakabayashi\n";
    while(1)
    {
        I2C_Transmit(I2C1_MODULE,0x56,testdata,13);
    }
}

void interrupt Handle(void)
{
    UART_Interrupt();
    I2C_Interrupt();
}

void Basic_Init(void)
{
    OSCCON = 0xF0;      //PLL ON: 
                        //internal Oscilltor is 32MHz
                        //clock source is internal one.
    
    TRISA = 0x00;       //All PORTA is output 
    ANSELA = 0x00;      //All PORTA  is digital
    WPUA = 0x00;        
    
    /*alternate pin fuction control*/
    APFCON = 0x00;     //no alteration
    
    PORTA = 0x00;       //clear
}

void UART_InitPort(void)
{
    TRISA &= ~(1<<4);
    ANSELA &= ~(1<<4);
    APFCON |= (1<<2);       //TX of UART assing to RA4
}
void I2C_InitPort(void)
{
    TRISA |= (1<<1);
    TRISA |= (1<<2);
    
    ANSELA &= ~(1<<1);
    ANSELA &= ~(1<<2);
}
