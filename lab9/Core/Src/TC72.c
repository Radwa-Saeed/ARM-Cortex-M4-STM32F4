/*
 * Author: Radwa_Saeed
 * Date   : 15/1/2022
 * Version: 1.0.0
 */
#include "TC72.h"
#include "SPI.h"
#include "Util.h"


void TC72_Init(unsigned char Mode) {
    /// TODO:
    TC72_RegisterWrite(0x80, 0x00);
}

void TC72_RegisterWrite(unsigned char RegAdd, unsigned char Data) {
  SPI1_TransmitRecieveByte(RegAdd | (1 << 7));
  SPI1_TransmitRecieveByte(Data);
}

void TC72_RegisterRead(unsigned char RegAdd, unsigned char* DataPtr) {
    SPI1_TransmitRecieveByte(RegAdd & (~(1 << 7)));
    *DataPtr = SPI1_TransmitRecieveByte(0x00);
}
