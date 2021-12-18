/*
 * Author : Radwa Saeed
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

extern unsigned char PressedKey;
extern unsigned char state;
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int main(void) {
	KeyPad_INIT();
	// 7 SEG INITIALIZATION AS OP
	GPIO_EnableClock(0);
	for (unsigned char i = 0; i < 7; i++) {GPIO_Init(0, i, OUTPUT, PUSH_PULL); }
  while(1){
	  KeyPad_Manage();
  }
  return 0;
}
void KeyPad_Callouts_KeyPressNotificaton(void){
	for (int i = 0; i < 7; i++) {GPIO_WritePin(0, i, (sevenSegHex[PressedKey] & (1 << i)) >> i);}
	//state = RELEASED;
}
