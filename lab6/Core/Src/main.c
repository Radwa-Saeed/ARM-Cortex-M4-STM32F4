/*
 * Author : Radwa Saeed
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void SevenSeg_INIT(void);

int main(void) {
	KeyPad_INIT();
	SevenSeg_INIT();

  while(1){
	  KeyPad_Manage();
  }
  return 0;
}

// 7 SEG INITIALIZATION AS OP
void SevenSeg_INIT(void){
		GPIO_EnableClock(0);
		for (unsigned char i = 0; i < 7; i++) {GPIO_Init(0, i, OUTPUT, PUSH_PULL); }
}

void KeyPad_Callouts_KeyPressNotificaton(void){
	unsigned char PressedKey= KeyPad_Getkey();
	for (unsigned char i = 0; i < 7; i++) {GPIO_WritePin(0, i, (sevenSegHex[PressedKey] & (1 << i)) >> i);}
}
