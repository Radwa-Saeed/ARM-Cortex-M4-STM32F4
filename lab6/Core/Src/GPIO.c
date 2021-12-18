/*
 * Author : Radwa_Saeed
 * Date   : 18/12/2021
 */

#include "GPIO.h"

//#include "stm32f401cc_interface.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

#define GPIO_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID + REG_ID))
// CLK ENABLE
#define RCC_AHB1ENR GPIO_REG(0x40023800 , 0x30)
// REGISTERS FOR GPIOA
#define GPIOA_MODER 	GPIO_REG(0x40020000 , 0x00)
#define GPIOA_OTYPER 	GPIO_REG(0x40020000 , 0x04)
#define GPIOA_PUPDR 	GPIO_REG(0x40020000 , 0x0C)
#define GPIOA_ODR 		GPIO_REG(0x40020000 , 0x10)
#define GPIOA_IDR 		GPIO_REG(0x40020000 , 0x14)
// REGISTERS FOR GPIOB
#define GPIOB_MODER 	GPIO_REG(0x40020400 , 0x00)
#define GPIOB_OTYPER 	GPIO_REG(0x40020400 , 0x04)
#define GPIOB_PUPDR 	GPIO_REG(0x40020400 , 0x0C)
#define GPIOB_ODR 		GPIO_REG(0x40020400 , 0x10)
#define GPIOB_IDR 		GPIO_REG(0x40020400 , 0x14)

unsigned int* lookup[2][5]={{GPIOA_MODER, GPIOA_OTYPER, GPIOA_PUPDR, GPIOA_ODR, GPIOA_IDR},
		{GPIOB_MODER, GPIOB_OTYPER, GPIOB_PUPDR, GPIOB_ODR, GPIOB_IDR}};

void GPIO_EnableClock(unsigned char PORT_ID) {
      *RCC_AHB1ENR |= (0x01 << PORT_ID);
}

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinMode,unsigned char DefaultState) {
	// Moder 0
	*lookup[PORT_ID][0] &= ~(0x03 << 2 * PinNum);
	*lookup[PORT_ID][0] |= PinMode << 2 * PinNum;
	// OTYPER 1
	*lookup[PORT_ID][1] &= ~(1 << PinNum);
	*lookup[PORT_ID][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;
	// PUPDR 2
	*lookup[PORT_ID][2] &= ~(0x03 << 2 * PinNum);
	*lookup[PORT_ID][2] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum,unsigned char Data) {
	unsigned char result;
	//CHECK IF MODER IS OP
	if (((*lookup[PORT_ID][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
		//GETTING DATA
		if (Data) {
			*lookup[PORT_ID][3] |= (1 << PinNum);
		} else {
			*lookup[PORT_ID][3] &= ~(1 << PinNum);
		}
		result = OK;
	} else {
		result = NOK;
	}
	return result;
}

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum) {
  unsigned char data = 0;
  data = (*lookup[PORT_ID][4] & (1 << PinNum)) >> PinNum;
  return data;
}
