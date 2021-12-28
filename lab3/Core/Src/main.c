#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"


int main(void) {
	//initializing output pins
	GPIO_Init('A', 0, OUTPUT, PUSH_PULL);
	while (1) {
		// TURN ON
		GPIO_WritePin('A', 0, 1);
		//delay
			for (int j = 0; j < 1000000; j++) {}
		// TURN OFF
		GPIO_WritePin('A', 0, 0);
		//delay
			for (int j = 0; j < 1000000; j++) {}
		}
	return 0;
}
