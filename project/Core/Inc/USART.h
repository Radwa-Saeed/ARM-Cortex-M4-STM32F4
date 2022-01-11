/*
 * USART.h
 *
 *  Created on: Dec 31, 2021
 *      Author: Radwa_Saeed
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#define USART_REG(BASE,OFFSET) *(unsigned int*)(BASE + OFFSET)

// ########## WORKING ON USART2 ON BUS APB1 ##########
#define RCC_APB1ENR 	(USART_REG(0x40023800,0x40))

// ######### USART2 REGISTERS (BASE => 0x40004400) ####
#define USART_SR 		(USART_REG(0x40004400,0x00))
#define USART_DR 		(USART_REG(0x40004400,0x04))
#define USART_BRR 		(USART_REG(0x40004400,0x08))
#define USART_CR1 		(USART_REG(0x40004400,0x0C))
#define USART_CR2 		(USART_REG(0x40004400,0x10))
#define USART_CR3 		(USART_REG(0x40004400,0x14))
#define USART_GTPR 		(USART_REG(0x40004400,0x18))

//############ INIT FUN #############################
void USART_INIT (unsigned int BAUDE_RATE , unsigned char MODE ,unsigned char WORD_LENGTH,unsigned char OVER_SAMPLING);

//########## TRANS VS RECIVE #######################
#define RECIEVER (2)
#define TRANSMITTER (3)
#endif /* INC_USART_H_ */
