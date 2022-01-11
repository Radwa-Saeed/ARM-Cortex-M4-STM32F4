#include "stm32f401cc_interface.h"
int main(void) {
	RCC_AHB1ENR |= (1 << 1); 		// Enable PORT B
	//GPIOB_MODER&=~(3<<6); 		// Config PORT B PIN 3 as I/P (DEFAULT)
	GPIOB_MODER |= (0x01 << 10); 	// Config PORT B PIN 5 as O/P
	GPIOB_MODER |= (0x01 << 12); 	// Config PORT B PIN 6 as O/P
	GPIOB_MODER |= (0x01 << 14); 	// Config PORT B PIN 7 as O/P
	//GPIOB_OTYPER&=~(1<<5); 		// Config O/P as Push-Pull (DEFAULT)
	GPIOB_PUPDR |= (0x01 << 6); 	// Config I/P as Pull-Up Res
	int delay = 0;
	int colors = 0;
	while (1) {
		if ((GPIOB_IDR & (1 << 3)) == 8) { //check if the button is not Pressed (default 1 active low  (Pressed:0, Not pressed :1))
			for (delay = 0; delay <= 2000; delay++) {
			}
			if ((GPIOB_IDR & (1 << 3)) == 0) { //check if the button is Pressed
				colors += 1;
				switch (colors) {
				case 1: {
					GPIOB_ODR = 0;
					GPIOB_ODR |= (1 << 5);
					break;
				}
				case 2: {
					GPIOB_ODR = 0;
					GPIOB_ODR |= (1 << 6);
					break;
				}
				case 3: {
					GPIOB_ODR = 0;
					GPIOB_ODR |= ((1 << 5) | (1 << 6));
					break;
				}
				case 4: {
					GPIOB_ODR = 0;
					GPIOB_ODR |= (1 << 7);
					break;
				}
				case 5: {
					GPIOB_ODR = 0;
					GPIOB_ODR |= ((1 << 5) | (1 << 7));
					break;
				}
				case 6: {
					GPIOB_ODR = 0;
					GPIOB_ODR |= ((1 << 6) | (1 << 7));
					break;
				}
				case 7: {
					GPIOB_ODR = 0;
					GPIOB_ODR |= ((1 << 5) | (1 << 6) | (1 << 7));
					break;
				}
				case 8: {
					GPIOB_ODR = 0;
					colors = 0;
				}
				}
			}
		}
	}
	return 0;

}

