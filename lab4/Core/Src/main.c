#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
//turn off all leds of 7 seg
void off(void) {
	GPIO_WritePin('A', 0, 0);
	GPIO_WritePin('A', 1, 0);
	GPIO_WritePin('A', 2, 0);
	GPIO_WritePin('A', 3, 0);
	GPIO_WritePin('A', 4, 0);
	GPIO_WritePin('A', 5, 0);
	GPIO_WritePin('A', 6, 0);
}
int main(void) {
	//initializing output pins
	GPIO_Init('A', 0, OUTPUT, PUSH_PULL);
	GPIO_Init('A', 1, OUTPUT, PUSH_PULL);
	GPIO_Init('A', 2, OUTPUT, PUSH_PULL);
	GPIO_Init('A', 3, OUTPUT, PUSH_PULL);
	GPIO_Init('A', 4, OUTPUT, PUSH_PULL);
	GPIO_Init('A', 5, OUTPUT, PUSH_PULL);
	GPIO_Init('A', 6, OUTPUT, PUSH_PULL);

	while (1) {
		for (int i = 0; i <= 9; i++) {
			//delay
			for (int j = 0; j < 1000000; j++) {
			}
			//counter
			switch (i) {
			case 0:
				off();
				GPIO_WritePin('A', 0, 1);
				GPIO_WritePin('A', 1, 1);
				GPIO_WritePin('A', 2, 1);
				GPIO_WritePin('A', 3, 1);
				GPIO_WritePin('A', 4, 1);
				GPIO_WritePin('A', 5, 1);
				break;
			case 1:
				off();
				GPIO_WritePin('A', 1, 1);
				GPIO_WritePin('A', 2, 1);
				break;
			case 2:
				off();
				GPIO_WritePin('A', 0, 1);
				GPIO_WritePin('A', 1, 1);
				GPIO_WritePin('A', 3, 1);
				GPIO_WritePin('A', 4, 1);
				GPIO_WritePin('A', 6, 1);
				break;
			case 3:
				off();
				GPIO_WritePin('A', 0, 1);
				GPIO_WritePin('A', 1, 1);
				GPIO_WritePin('A', 2, 1);
				GPIO_WritePin('A', 3, 1);
				GPIO_WritePin('A', 6, 1);
				break;
			case 4:
				off();
				GPIO_WritePin('A', 1, 1);
				GPIO_WritePin('A', 2, 1);
				GPIO_WritePin('A', 5, 1);
				GPIO_WritePin('A', 6, 1);
				break;
			case 5:
				off();
				GPIO_WritePin('A', 0, 1);
				GPIO_WritePin('A', 2, 1);
				GPIO_WritePin('A', 3, 1);
				GPIO_WritePin('A', 5, 1);
				GPIO_WritePin('A', 6, 1);
				break;
			case 6:
				off();
				GPIO_WritePin('A', 0, 1);
				GPIO_WritePin('A', 2, 1);
				GPIO_WritePin('A', 3, 1);
				GPIO_WritePin('A', 4, 1);
				GPIO_WritePin('A', 5, 1);
				GPIO_WritePin('A', 6, 1);
				break;
			case 7:
				off();
				GPIO_WritePin('A', 0, 1);
				GPIO_WritePin('A', 1, 1);
				GPIO_WritePin('A', 2, 1);
				break;
			case 8:
				off();
				GPIO_WritePin('A', 0, 1);
				GPIO_WritePin('A', 1, 1);
				GPIO_WritePin('A', 2, 1);
				GPIO_WritePin('A', 3, 1);
				GPIO_WritePin('A', 4, 1);
				GPIO_WritePin('A', 5, 1);
				GPIO_WritePin('A', 6, 1);
				break;
			case 9:
				off();
				GPIO_WritePin('A', 0, 1);
				GPIO_WritePin('A', 1, 1);
				GPIO_WritePin('A', 2, 1);
				GPIO_WritePin('A', 3, 1);
				GPIO_WritePin('A', 5, 1);
				GPIO_WritePin('A', 6, 1);
				break;
			default:
				break;
			}
		}
	}
	return 0;
}
