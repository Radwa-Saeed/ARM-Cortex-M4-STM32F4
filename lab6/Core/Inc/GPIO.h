/*
 * Author : Radwa_Saeed
 * Date   : 18/12/2021
 */
#ifndef GPIO_H
#define GPIO_H

#include "stm32f401xc.h"

// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)



// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

void GPIO_EnableClock(unsigned char PORT_ID);

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinDir,
               unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum,unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum);

#endif /* GPIO_H */
