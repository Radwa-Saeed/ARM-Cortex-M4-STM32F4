/*
 * USART.c
 *
 *  Created on: Dec 31, 2021
 *      Author: Radwa_Saeed
 */
#include "USART.h"
void USART_INIT (unsigned int BAUDE_RATE , unsigned char MODE ,unsigned char WORD_LENGTH,unsigned char OVER_SAMPLING){
	RCC_APB1ENR |=1<<17 ; // BUS APB1 ClCK ENABLE
	USART_CR1 |= 1<<13; // USART ENABLE
	USART_BRR = BAUDE_RATE; // SETTING THE BAUDE RATE
	USART_CR1 |= 1<< MODE; // TE 1<<3 , RE 1<<2
	switch (WORD_LENGTH) {
		case 8:
			USART_CR1 &= ~(1<<12);
			break;
		case 9:
			USART_CR1 |= (1<<12);
			break;
		default:
			break;
	}
	switch (OVER_SAMPLING) {
		case 16:
			USART_CR1 &= ~(1 << 15);
			break;
		case 8:
			USART_CR1 |= (1 << 15);
		break;
		default:
			break;
	}
	USART_CR2 &= ~(0x03 << 12 ); // SETTING NO. OF STOP BITS TO 1

}

