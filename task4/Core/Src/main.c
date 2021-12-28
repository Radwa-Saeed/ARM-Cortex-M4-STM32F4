/*
 * Author : Dalia_Lotfy
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "EXTI.h"

void SevenSeg_INIT(void);
void PushButton_INIT(void);
void Inc_ISR(void);
void Dec_ISR(void);
void Counter(void);

unsigned char counter = 0;
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int main(void) {

	EXTI_EnableClock(); 					// ENABLE EXTERNAL INTERRUPT CLOCK CONFIG
	EXIT_INIT(1, 0, FALLING);
	EXIT_INIT(1, 1, FALLING);
	SevenSeg_INIT();
	PushButton_INIT();

  while(1){
	  Counter();
  }
  return 0;
}

void SevenSeg_INIT(void){
	GPIO_EnableClock(0);
	for (unsigned char i = 0; i < 7; i++) {GPIO_Init(0, i, OUTPUT, PUSH_PULL);}
}

void PushButton_INIT(void){
	GPIO_EnableClock(1);
	GPIO_Init(1, 0, INPUT, PULL_UP);
	GPIO_Init(1, 1, INPUT, PULL_UP);
	}

void Inc_ISR(void){
	(*EXTI_PR) |= (0x01 << 0x00);
	if (counter <10){
		counter++;
	}
}
void Dec_ISR(void){
	(*EXTI_PR) |= (0x01 << 0x01);
		if (counter >0){
			counter--;
		}
}
void Counter(void){
	for (unsigned char i = 0; i < 7; i++) {GPIO_WritePin(0, i, (sevenSegHex[counter] & (1 << i)) >> i);}
}



