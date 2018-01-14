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
    
    I2C1_Init(I2C_InitPort,0x00,I2C_MODE_MASTER,I2C_SPEED_HIGH);
    
    UART_Init(UART_InitPort,BAUD_9600);
    
    __delay_ms(100);
    
    MPU6050_Init();

    __delay_ms(100);

    Timer0_Init(TMR0_PRESCALER64,125);//set interrupt time is 1ms
    
    while(1)
    {
        
    }
}

void SWAP(uint8_t *x,uint8_t *y) 
{
    uint8_t swap = *x; 
    *x = *y; 
    *y = swap;
}

void interrupt Handle(void)
{
    static accel_t_gyro_union accel_t_gyro;
    static uint16_t count = 0;
    
    if(Timer0_CheckFlag())
    {
        count++;
        if(count>500)
        {
            count = 0;
            MPU6050_Read_MultiData(MPU6050_ACCEL_XOUT_H,(uint8_t *)&accel_t_gyro,sizeof(accel_t_gyro));

            SWAP(&accel_t_gyro.reg.x_accel_h, &accel_t_gyro.reg.x_accel_l);
            SWAP(&accel_t_gyro.reg.y_accel_h, &accel_t_gyro.reg.y_accel_l);
            SWAP(&accel_t_gyro.reg.z_accel_h, &accel_t_gyro.reg.z_accel_l);
            SWAP(&accel_t_gyro.reg.t_h, &accel_t_gyro.reg.t_l);
            SWAP(&accel_t_gyro.reg.x_gyro_h, &accel_t_gyro.reg.x_gyro_l);
            SWAP(&accel_t_gyro.reg.y_gyro_h, &accel_t_gyro.reg.y_gyro_l);
            SWAP(&accel_t_gyro.reg.z_gyro_h, &accel_t_gyro.reg.z_gyro_l);

            UART_Transmit(0xFF);
            UART_Transmit(0xFF);
            UART_Transmit(0xFF);
            UART_Transmit(0xFF);
            UART_Transmit(0xFF);

            UART_Transmit(accel_t_gyro.reg.x_accel_h);
            UART_Transmit(accel_t_gyro.reg.x_accel_l);
            UART_Transmit(accel_t_gyro.reg.y_accel_h);
            UART_Transmit(accel_t_gyro.reg.y_accel_l);
            UART_Transmit(accel_t_gyro.reg.z_accel_h);
            UART_Transmit(accel_t_gyro.reg.z_accel_l);

            UART_Transmit(accel_t_gyro.reg.t_h);
            UART_Transmit(accel_t_gyro.reg.t_l);

            UART_Transmit(accel_t_gyro.reg.x_gyro_h);
            UART_Transmit(accel_t_gyro.reg.x_gyro_l);
            UART_Transmit(accel_t_gyro.reg.y_gyro_h);
            UART_Transmit(accel_t_gyro.reg.y_gyro_l);
            UART_Transmit(accel_t_gyro.reg.z_gyro_h);
            UART_Transmit(accel_t_gyro.reg.z_gyro_l);

//            printf("%x %x %x %x \n",accel_t_gyro.value.x_accel,accel_t_gyro.reg.x_accel_h, accel_t_gyro.reg.x_accel_l);
    
        }
    }
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
    APFCON |= (1<<7);       //RX of UART assing to RA5
}
void I2C_InitPort(void)
{
    TRISA |= (1<<1);
    TRISA |= (1<<2);
    
    ANSELA &= ~(1<<1);
    ANSELA &= ~(1<<2);
}
