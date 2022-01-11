#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {
	//CONFIGURING INPUT/OUTPUT PINS AND MODES
	GPIO_Init('B', 3, INPUT, PULL_UP);
	GPIO_Init('B', 5, OUTPUT, PUSH_PULL);
	GPIO_Init('B', 6, OUTPUT, PUSH_PULL);
	GPIO_Init('B', 7, OUTPUT, PUSH_PULL);
	int delay = 0;
	int colors = 0;
	while (1) {
		if (GPIO_ReadPin('B', 3) == NOK) { //check if the button is not Pressed (default 1 active low  (Pressed:0, Not pressed :1))
			for (delay = 0; delay <= 2000; delay++) {
			}
			if (GPIO_ReadPin('B', 3) == OK) { //check if the button is Pressed
				colors += 1;
				GPIO_WritePin('B', 5, colors&1);
				GPIO_WritePin('B', 6, (colors>>1)&1);
				GPIO_WritePin('B', 7, (colors>>2)&1);
			}
		}
	}
	return 0;
}
