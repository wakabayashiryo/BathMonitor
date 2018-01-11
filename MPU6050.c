
// I2CにアクセスするためにWireライブラリを使用
#include "MPU6050.h"

int8_t MPU6050_Write_Data(uint8_t reg,uint8_t pData)
{
    int8_t result = 0;
    
    result += I2C_Transmit(I2C1_MODULE,MPU6050_I2C_ADDRESS,&reg,1);
    
    result += I2C_Transmit(I2C1_MODULE,MPU6050_I2C_ADDRESS,&pData,1);
    
    return result;
}

int8_t MPU6050_Read_Data(uint8_t reg,uint8_t *pData)
{
    int8_t result = 0;

    result += I2C_Transmit(I2C1_MODULE,MPU6050_I2C_ADDRESS,&reg,1);
    
    result += I2C_Receive(I2C1_MODULE,MPU6050_I2C_ADDRESS,pData,1);
    
    return result;
}

int8_t MPU6050_Read_MultiData(uint8_t reg,uint8_t *pData,uint8_t size)
{
    int8_t result = 0;

    result += I2C_Transmit(I2C1_MODULE,MPU6050_I2C_ADDRESS,&reg,1);
    result += I2C_Receive(I2C1_MODULE,MPU6050_I2C_ADDRESS,pData,size);
    
    return result;
}

int8_t MPU6050_Init(void)
{
    int8_t result;

    uint8_t addr;
    result = MPU6050_Read_Data(MPU6050_WHO_AM_I,&addr);
    if((addr>>1)!=MPU6050_I2C_ADDRESS)  return -1;
//        while(1)printf("%d \n",result);

    uint8_t data = 0x00;
    result += MPU6050_Write_Data(MPU6050_PWR_MGMT_1,data);
    
    result += MPU6050_Read_Data(MPU6050_PWR_MGMT_1,&data);
    
    return result;
}
