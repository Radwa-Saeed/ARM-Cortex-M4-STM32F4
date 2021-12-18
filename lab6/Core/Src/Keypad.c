/*
 * Author : Radwa_Saeed
 * Date   : 8/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

// KEYPAD INITIALIZATION 1,2,3 => OP / A,B,C,D => IP
void KeyPad_INIT(void) {
	GPIO_EnableClock(1);
	for (unsigned char i = 0; i < 3; i++) {
		GPIO_Init(1, i, OUTPUT, PUSH_PULL);
	}
	for (unsigned char j = 3; j < 7; j++) {
		GPIO_Init(1, j, INPUT, PULL_UP);
	}
}

//unsigned char State = 0;
char KeyPad_Getkey(int row, int col) {
	char keys[4][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 0, 0, 0 } };
	char keyValue = keys[row][col];
	return keyValue;
}

unsigned char state = RELEASED; //1
unsigned char PressedKey;

void KeyPad_Manage(void) {
	int row, col;
	if (state == RELEASED) {
	for (col = 0; col < 3; col++) {
		for (unsigned char i = 0; i < 3; i++) {
			GPIO_WritePin(1, i, 1);
		}
		GPIO_WritePin(1, col, 0);
			for (row = 3; row < 7; row++) {
				if (GPIO_ReadPin(1, row) == 0) {
					for (unsigned int i = 0; i < 3000; i++) {
					}
					if (GPIO_ReadPin(1, row) == 0) {
						state = PRESSED;
						PressedKey = KeyPad_Getkey(row - 3, col);
						KeyPad_Callouts_KeyPressNotificaton();
					}
				}
				if (GPIO_ReadPin(1, row) == 1) {
					for (unsigned int i = 0; i < 3000; i++) {
					}
					if (GPIO_ReadPin(1, row) == 1) {
						state = RELEASED;
					}
				}
			}

		}
	}
}

