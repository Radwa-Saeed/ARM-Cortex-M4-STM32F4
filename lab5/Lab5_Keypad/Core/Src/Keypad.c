/*
 * Author : Radwa_Saeed
 * Date   : 8/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"
#include "stm32f401cc_interface.h"

unsigned char state = RELEASED; // 1
unsigned char keys[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 0, 0, 0 } };
unsigned char keyValue ;

// KEYPAD INITIALIZATION 1,2,3 => OP / A,B,C,D => IP
void KeyPad_INIT(void) {
	GPIO_EnableClock('B');
	for (unsigned char i = 0; i < 3; i++) {
		GPIO_Init('B', i, OUTPUT, PUSH_PULL);
	}
	for (unsigned char j = 3; j < 7; j++) {
		GPIO_Init('B', j, INPUT, PULL_UP);
	}
}

void KeyPad_Manage(void) {
	unsigned char row, col;
	if(state == RELEASED){
		for(col=0;col<3;col++){
			GPIO_WritePin('B', col, 0);
			for(row=0;row<4;row++){
				if(GPIO_ReadPin('B', row+3)==0){
					for (unsigned int i = 0; i < 5000; i++) {} //delay
					if(GPIO_ReadPin('B', row+3)==0){
						keyValue = keys[row][col];
						state=PRESSED;
						KeyPad_Callouts_KeyPressNotificaton();
					}
				}

			}
			GPIO_WritePin('B', col, 1);
		}
	}
}

unsigned char KeyPad_Getkey(void) {
	if(state == PRESSED){
		state = RELEASED;
		return keyValue;
	}
	else{
		return -1;
	}
}
