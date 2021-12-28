/*
 * EXTI.c
 *
 *  Created on: Dec 29, 2021
 *      Author: Dalia_Lotfy
 */
#include "EXTI.h"

unsigned int * Exti[4]={SYSCFG_EXTICR1,SYSCFG_EXTICR2,SYSCFG_EXTICR3,SYSCFG_EXTICR4};
void EXTI_EnableClock(void)
{
	(*RCC_APB2ENR) |= (0x01 << 14); ////// WHY NOT 0X14
}

void EXIT_INIT(char Port, int EXTx, char state){
	(*SYSCFG_EXTICR1) |= Port<<(4*EXTx);
	(*EXTI_IMR) |=(1<<EXTx);
	//EXTI_RTSR |= ((RISING_MASK(state)) << EXTx);
	(*EXTI_FTSR) |= ((FALLING_MASK(state)) << EXTx);
	(*NVIC_ISER0)|=1<<(6+EXTx);
}


