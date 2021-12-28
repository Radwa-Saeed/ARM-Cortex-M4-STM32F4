/*
 * Author : Radwa_Saeed
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "EXTI.h"

void Toggle_Led_ISR(void);  // Called only in startup file
void Led_Button_INIT(void);

int main(void) {
	EXTI_EnableClock(); 					// ENABLE EXTERNAL INTERRUPT CLOCK CONFIG
	/*(*SYSCFG_EXTICR1) &=(0x00 << 0x00); 	//  PORT A as source input for the EXTI0 (bin 0)
	(*EXTI_IMR) |=(0x01 << 0x00); 			// Interrupt request from line 0 is not masked
	(*EXTI_FTSR) |=(0x01 << 0x00); 			//  Falling trigger selection register
	(*NVIC_ISER0) = (0x01 << 0x06);*/
	//EXIT_INIT(Port, EXTx, state)
	EXIT_INIT(0, 0, FALLING);
	Led_Button_INIT();

  while(1){
  }
  return 0;
}
void Toggle_Led_ISR(void){
	(*EXTI_PR) |= (0x01 << 0x00); 			// Clear EXTI Flag
	if (GPIO_ReadPin(0, 1) == 0){
		GPIO_WritePin(0, 1, 1);
	}
	else if (GPIO_ReadPin(0, 1) == 1){
		GPIO_WritePin(0, 1, 0);
	}
}

void Led_Button_INIT(void){
	// LED & PUSH BUTTON CONFIG
	GPIO_EnableClock(0);
	GPIO_Init(0, 0, INPUT, PULL_UP);
	GPIO_Init(0, 1, OUTPUT, PUSH_PULL);
}


