#include "I2C.h"

void RTC_Init(void) {
    I2C1_Start();   
    I2C1_MasterTxAddr(0xD0);
    I2C1_MasterTxSingleData(0x07);
    I2C1_MasterTxSingleData(0x00);
    I2C1_Stop(); 
}

void RTC_GetTime(unsigned char *h, unsigned char *m, unsigned char *s) {
    I2C1_Start();   
    I2C1_MasterTxAddr(0xD0);
    I2C1_MasterTxSingleData(0x00);
    I2C1_Stop();

    /* Read Time Data */
    
}

void RTC_SetTime(unsigned char Buffer[]){
}
