
/*
 * Author: Radwa_Saeed
 * Date   : 15/12/2021
 * Version: 1.0.0
 */
#ifndef GPIO_H
#define GPIO_H


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


#define SPEED_LOW            ((unsigned char)0x00)
#define SPEED_MEDIUM         ((unsigned char)0x08)
#define SPEED_HIGH           ((unsigned char)0x10)
#define SPEED_VERY_HIGH      ((unsigned char)0x18)


void GPIO_EnableClock(unsigned char PortId );

void GPIO_Init(unsigned char PortId, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum,
                            unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum);

#endif /* GPIO_H */
