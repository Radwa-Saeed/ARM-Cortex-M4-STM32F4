/*
 * Author : Radwa_Saeed
 * Date   : 18/12/2021
 */

#include "GPIO.h"

#define GPIO_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

// CLK ENABLE
#define RCC_AHB1ENR 	(GPIO_REG(0x40023800 , 0x30))

// REGISTERS FOR GPIOA
#define GPIOA_MODER 	GPIO_REG(0x40020000 , 0x00)
#define GPIOA_OTYPER 	GPIO_REG(0x40020000 , 0x04)
#define GPIOA_PUPDR 	GPIO_REG(0x40020000 , 0x0C)
#define GPIOA_ODR 		GPIO_REG(0x40020000 , 0x14)
#define GPIOA_IDR 		GPIO_REG(0x40020000 , 0x10)

// REGISTERS FOR GPIOB
#define GPIOB_MODER 	GPIO_REG(0x40020400 , 0x00)
#define GPIOB_OTYPER 	GPIO_REG(0x40020400 , 0x04)
#define GPIOB_PUPDR 	GPIO_REG(0x40020400 , 0x0C)
#define GPIOB_ODR 		GPIO_REG(0x40020400 , 0x14)
#define GPIOB_IDR 		GPIO_REG(0x40020400 , 0x10)



unsigned int* lookup[2][6]={{RCC_AHB1ENR,GPIOA_MODER, GPIOA_OTYPER, GPIOA_PUPDR, GPIOA_ODR, GPIOA_IDR},
		{RCC_AHB1ENR,GPIOB_MODER, GPIOB_OTYPER, GPIOB_PUPDR, GPIOB_ODR, GPIOB_IDR}};

void GPIO_EnableClock(unsigned char PORT_ID) {
      *(lookup[PORT_ID][0]) |= (0x01 << PORT_ID);
}

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinMode,unsigned char DefaultState) {
	// Moder 0
	*lookup[PORT_ID][1] &= ~(0x03 << 2 * PinNum);
	*lookup[PORT_ID][1] |= PinMode << 2 * PinNum;
	// OTYPER 1
	*lookup[PORT_ID][2] &= ~(1 << PinNum);
	*lookup[PORT_ID][2] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;
	// PUPDR 2
	*lookup[PORT_ID][3] &= ~(0x03 << 2 * PinNum);
	*lookup[PORT_ID][3] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum,unsigned char Data) {
	unsigned char result;
	//CHECK IF MODER IS OP
	if (((*lookup[PORT_ID][1] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
		//GETTING DATA
		if (Data) {
			*lookup[PORT_ID][4] |= (1 << PinNum);
		} else {
			*lookup[PORT_ID][4] &= ~(1 << PinNum);
		}
		result = OK;
	} else {
		result = NOK;
	}
	return result;
}

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum) {
  unsigned char data = 0;
  data = (*lookup[PORT_ID][5] & (1 << PinNum)) >> PinNum;
  return data;
}
