/*
 * Author : Radwa_Saeed
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "USART.h"


void TRANSMIT_DATA (char *Data);
void TRANSMITTER_PIN_INIT (void);

int main(void) {
	//USART_INIT(BAUDE_RATE, MODE, WORD_LENGTH, OVER_SAMPLING)
	USART_INIT(0x683, TRANSMITTER, 8, 16);
	TRANSMITTER_PIN_INIT();
	char Data[] = {"HELLO WORLD !"};
	TRANSMIT_DATA(Data);
  while(1){}
  return 0;
}

void TRANSMIT_DATA (char *Data){
	unsigned char i =0;
	while(Data[i]){
		USART_DR = Data[i];
		while (((USART_SR>>6)&1)==0){}
		i++;
	}
}

void TRANSMITTER_PIN_INIT (void){
	// CONFIG PORT A PIN 2
	GPIO_EnableClock(0);
	GPIO_Init(0, 2, ALTERNATE_FUN, PUSH_PULL);
	(*GPIOA_AFRL) |=0x07 <<8; // Alternate Function to USART2 ON AF7
}

