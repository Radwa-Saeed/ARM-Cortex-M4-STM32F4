/*
 * DMA.c
 *
 *  Created on: Jan 4, 2022
 *      Author: Radwa_Saeed
 */

#include "DMA.h"
#include "GPIO.h"
#include "EXTI.h"

void DMA_EnableClock(unsigned char DMA_Num){
	(*RCC_AHB1ENR) |= 1 << DMA_Num;
	/* Make sure that the DMA2 stream 0 is disabled */
	if (DMA2_S0CR){
		DMA2_S0CR = 0; //
		while (DMA2_S0CR) {}  //Wait Until DMA2 Stream0 Disable
	}
}

void DMA2_Stream0_Config (char DIR, char PSIZE,char MSIZE,char PINC, char MINC, char TCIE,char FIFO){
	(*NVIC_ISER1) = 1<<24; 	// Enable Stream 0 interrupt
	DMA2_S0CR |=(DIR<<6); 	// Configuration transfer direction
	DMA2_S0CR |=((PINC<<9)|(MINC<<10)); //Select peripheral & memory incremented mode
	DMA2_S0CR |=((PSIZE<<11)|(PSIZE<<13)); //Select memory & peripheral size
	DMA2_S0CR |=(TCIE<<4); //Enable DMA transfer complete interrupt
	//DMA2_S0FCR |=(1<<2); //Enable FIFO mode
	DMA2_S0FCR = FIFO; //Select FIFO threshold level 1/4 FIFO
}

void DMA2_Stream0_Set_Addresses( unsigned int* src, unsigned int* dst)
{
  DMA2_S0PAR = (unsigned int)src;	//Set the source address to the peripheral port
  DMA2_S0MAR = (unsigned int)dst;	//Set the destination address to the memory port
}

void DMA2_Stream0_Enable(unsigned int items_no){
	DMA2_S0NDTR =items_no;	//Set number of data items
	DMA2_S0CR |= 1;
}

void DMA2_Stream0_IntClr(void){
	DMA2_LIFCR |= (1<<0)| (1<<2) | (1<<3) | (1<<4) | (1<<5); // Clear all interrupt flags
}

