#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"


int main(void) {
	//initializing output pins
	for(int i=0;i<7;i++){
		GPIO_Init('A', i, OUTPUT, PUSH_PULL);
	}
	// 7 SEG lookup table
	unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	while (1) {
		// counter from 0 to 9
		for (int i = 0; i <= 9; i++) {
			for (int n = 0; n < 7; n++) {GPIO_WritePin('A', n, (sevenSegHex[i] & (1 << n)) >> n);}
			//delay
			for (int j = 0; j < 1000000; j++) {}
		}
	}
	return 0;
}
