//
//// I2CにアクセスするためにWireライブラリを使用
//#include "MPU6050.h"
//
//void MPU6050_Init(void)
//{
//  uint16_t error;
//  uint8_t c;
//
//  // 初回の読み出し
//  error = MPU6050_Read_Register(MPU6050_WHO_AM_I, &c, 1);
//  printf("WHO_AM_I : %d",c);
//
//  // 動作モードの読み出し
//  error = MPU6050_read(MPU6050_PWR_MGMT_1, &c, 1);
//  printf("PWR_MGMT_1 : %d",c);
//  
//  // MPU6050動作開始
//  MPU6050_Write_Register(MPU6050_PWR_MGMT_1, 0);
//}
//
//// MPU6050_read
//int MPU6050_read(int start, uint8_t *buffer, int size) 
//{
//  int i, n, error;
//  Wire.beginTransmission(MPU6050_I2C_ADDRESS);
//  n = Wire.write(start);
//  if (n != 1) {
//    return (-10);
//  }
//  n = Wire.endTransmission(false);// hold the I2C-bus
//  if (n != 0) {
//    return (n);
//  }
//  // Third parameter is true: relase I2C-bus after data is read.
//  Wire.requestFrom(MPU6050_I2C_ADDRESS, size, true);
//  i = 0;
//  while (Wire.available() && i < size) {
//    buffer[i++] = Wire.read();
//  }
//  if ( i != size) {
//    return (-11);
//  }
//  return (0); // return : no error
//}
//
//// MPU6050_write
//int MPU6050_write(int start, const uint8_t *pData, int size) {
//  int n, error;
//  Wire.beginTransmission();
//  n = Wire.write(start);// write the start address
//  if (n != 1) {
//    return (-20);
//  }
//  n = Wire.write(pData, size);// write data bytes
//  if (n != size) {
//    return (-21);
//  }
//  error = Wire.endTransmission(true); // release the I2C-bus
//  if (error != 0) {
//    return (error);
//  }
//
//  return (0);// return : no error
//}
//
//// MPU6050_write_reg
//int MPU6050_write_reg(int reg, uint8_t data) 
//{
//  error = I2C_Transmit(I2C1_MODULE,MPU6050_I2C_ADDRESS, &data, 1);
//};
//
