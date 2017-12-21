/* 
 * File:   MPU6050.h
 * Author: evaota
 *
 * Created on 2017/12/21, 14:07
 */

#ifndef MPU6050_H
#define	MPU6050_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"

// レジスタアドレス
#define MPU6050_ACCEL_XOUT_H 0x3B  // R  
#define MPU6050_WHO_AM_I     0x75  // R
#define MPU6050_PWR_MGMT_1   0x6B  // R/W
#define MPU6050_I2C_ADDRESS  0x68

// 構造体定義
typedef union  {
  struct {
    uint8_t x_accel_h;
    uint8_t x_accel_l;
    uint8_t y_accel_h;
    uint8_t y_accel_l;
    uint8_t z_accel_h;
    uint8_t z_accel_l;
    uint8_t t_h;
    uint8_t t_l;
    uint8_t x_gyro_h;
    uint8_t x_gyro_l;
    uint8_t y_gyro_h;
    uint8_t y_gyro_l;
    uint8_t z_gyro_h;
    uint8_t z_gyro_l;
  }
  reg;
  struct {
    int16_t x_accel;
    int16_t y_accel;
    int16_t z_accel;
    int16_t temperature;
    int16_t x_gyro;
    int16_t y_gyro;
    int16_t z_gyro;
  }
  value;
}accel_t_gyro_union;

#ifdef	__cplusplus
}
#endif

#endif	/* MPU6050_H */

