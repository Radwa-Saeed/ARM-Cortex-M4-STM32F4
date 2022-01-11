/*
 * GPIO.C
 */
#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
void GPIO_Init(char Port, unsigned int PIN_NO, unsigned int PIN_Dir,unsigned int Default_State) {
	//enable clock of port
	switch (Port) {
	case ('A'):
		RCC_AHB1ENR |= (0x01 << 0);
		//configure moder register for pin direction
		switch (PIN_Dir) {
		case (INPUT):
			GPIOA_MODER &= ~(0x03 << 2 * PIN_NO);
			switch (Default_State) {
			case (PULL_UP):
				GPIOA_PUPDR |= (0x01 << 2 * PIN_NO);
				break;
			case (PULL_DOWN):
				GPIOA_PUPDR |= (0x10 << 2 * PIN_NO);
				break;
			}
			break;
		case (OUTPUT):
			GPIOA_MODER |= (0x01 << 2 * PIN_NO);
			switch (Default_State) {
			case (PUSH_PULL):
				GPIOA_OTYPER &= ~(0x01 << PIN_NO);
				break;
			case (OPEN_DRAIN):
				GPIOA_OTYPER |= (0x01 << PIN_NO);
				break;
			}
			break;
		case (ALTERNATE_FUN):
			GPIOA_MODER |= (0x02 << 2 * PIN_NO);
			break;
		case (ANALOG):
			GPIOA_MODER |= (0x03 << 2 * PIN_NO);
			break;
		} // end switch
		  //configure default state
		  //end switch
		break;
	case ('B'):
		RCC_AHB1ENR |= (0x01 << 1);
		//configure moder register for pin direction
		switch (PIN_Dir) {
		case (INPUT):
			GPIOB_MODER &= ~(0x03 << 2 * PIN_NO);
			switch (Default_State) {
			case (PULL_UP):
				GPIOB_PUPDR |= (0x01 << 2 * PIN_NO);
				break;
			case (PULL_DOWN):
				GPIOB_PUPDR |= (0x10 << 2 * PIN_NO);
				break;
			}
			break;
		case (OUTPUT):
			GPIOB_MODER |= (0x01 << 2 * PIN_NO);
			switch (Default_State) {
			case (PUSH_PULL):
				GPIOB_OTYPER &= ~(0x01 << PIN_NO);
				break;
			case (OPEN_DRAIN):
				GPIOB_OTYPER |= (0x01 << PIN_NO);
				break;
			}
			break;
		case (ALTERNATE_FUN):
			GPIOB_MODER |= (0x02 << 2 * PIN_NO);
			break;
		case (ANALOG):
			GPIOB_MODER |= (0x03 << 2 * PIN_NO);
			break;
		}				// end switch
		//end switch
		break;
	}

}

unsigned char GPIO_WritePin(char Port, unsigned int PIN_NO, unsigned int Data) {
	unsigned char result;
	switch (Port) {
	case ('A'):
		if ((GPIOA_MODER & (0x03 << 2 * PIN_NO)) >> (2 * PIN_NO) == 1) {
			if (Data) {
				GPIOA_ODR |= (1 << PIN_NO);
			} else {
				GPIOA_ODR &= ~(1 << PIN_NO);
			}
			result = OK;
		} else {
			result = NOK;
		}
		break;
	case ('B'):
		if ((GPIOB_MODER & (0x01 << 2 * PIN_NO)) >> (2 * PIN_NO)) {
			if (Data) {
				GPIOB_ODR |= (1 << PIN_NO);
			} else {
				GPIOB_ODR &= ~(1 << PIN_NO);
			}
			result = OK;
		} else {
			result = NOK;
		}

		break;

	}				// end switch

	return result;
}
unsigned char GPIO_ReadPin(char Port, unsigned int PIN_NO) {
	unsigned char result;
	switch (Port) {
	case 'A':
		if ((GPIOA_MODER & (0x03 << 2 * PIN_NO)) >> (2 * PIN_NO) == 0) {
			if ((GPIOA_IDR & (0x01 << PIN_NO)) >> PIN_NO == 1) {
				result = NOK;
			} else {
				result = OK;
			}
		}
		break;
	case 'B':
		if ((GPIOB_MODER & (0x01 << 2 * PIN_NO)) >> (2 * PIN_NO) == 0) {
			if ((GPIOB_IDR & (0x01 << PIN_NO)) >> PIN_NO == 1) {
				result = NOK; //1
			} else {
				result = OK; //0
			}
		}
		break;

	default:
		break;
	}
	return result;
}
