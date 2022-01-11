#include "GPIO.h"
#include "DMA.h"
#include "USART.h"

void TRANSMIT_DATA (unsigned int *Data);
void TRANSMITTER_PIN_INIT (void);

int main(void) {
	// Configuring PortA Bin0 O/P As Indicator of Transmission Complete
	GPIO_EnableClock(0);
    GPIO_Init(0, 0, OUTPUT, PUSH_PULL);
    GPIO_Init(0, 1, OUTPUT, PUSH_PULL);

    // ######## CLIENT SIDE ############
    unsigned int Size=100;
    unsigned int Src[Size],Dist[Size];
    for(int i=0; i<100; i++){Src[i]=(i+1)*100;}

    // ######## DMA ENABEL & CONFIG ###################
    DMA_EnableClock(DMA2_EN);
	DMA2_Stream0_Config(DMA_DIR_MM,DMA_DATA_WORD,DMA_DATA_WORD,DMA_EN,DMA_EN, DMA_TCIE_EN,DMA_FIFO_QUART);
	DMA2_Stream0_Set_Addresses(Src, Dist);
	DMA2_Stream0_Enable(Size);

	//USART_INIT(BAUDE_RATE, MODE, WORD_LENGTH, OVER_SAMPLING)
	USART_INIT(0x683, TRANSMITTER, 8, 16);
	TRANSMITTER_PIN_INIT();
	TRANSMIT_DATA(Dist);

	if(Dist[5]==Src[5]){
		GPIO_WritePin(0, 1, 1);
	}
    while (1)
    {

    }

  return 0;
}

void DMA2_Stream0_IRQHandler(void)
{
	GPIO_WritePin(0, 0, 1);
	DMA2_Stream0_IntClr();//To Clear Interrupt
}

void TRANSMIT_DATA (unsigned int *Data){
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

