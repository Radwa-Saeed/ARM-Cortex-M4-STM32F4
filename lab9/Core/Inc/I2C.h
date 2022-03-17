/*
 * Author: Radwa_Saeed
 * Date   : 17/1/2022
 * Version: 1.0.0
 */

#ifndef I2C_H
#define I2C_H

#define ACK  1
#define NACK 0

void I2C1_Init();

void I2C1_Start();

void I2C1_Stop();

void I2C1_MasterTxAddr(unsigned char SlaveAddr);

void I2C1_MasterTxSingleData(unsigned char Data);

void I2C1_MasterTxMultiData(unsigned char DataPtr[], unsigned int Size);

void I2C1_MasterRxMulti(unsigned char SlaveAddr, unsigned char * Buffer, unsigned int Size);


#endif /* I2C_H */
