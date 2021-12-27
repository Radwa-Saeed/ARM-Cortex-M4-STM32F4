

#include "GPIO.h"

unsigned int * Lookup[2][10] = {{GPIOA_MODER,GPIOA_OTYPER,GPIOA_OSPEEDR,GPIOA_PUPDR,GPIOA_IDR,GPIOA_ODR,GPIOA_BSRR,GPIOA_LCKR,GPIOA_AFRL,GPIOA_AFRH},
								{GPIOB_MODER,GPIOB_OTYPER,GPIOB_OSPEEDR,GPIOB_PUPDR,GPIOB_IDR,GPIOB_ODR,GPIOB_BSRR,GPIOB_LCKR,GPIOB_AFRL,GPIOB_AFRH}} ;
// ###################### LAB 7 #####################
unsigned int * Exti[4]={SYSCFG_EXTICR1,SYSCFG_EXTICR2,SYSCFG_EXTICR3,SYSCFG_EXTICR4};
void EXTI_EnableClock(void)
{
	(*RCC_APB2ENR) |= (0x01 << 14); ////// WHY NOT 0X14
}

void EXTI_PORT_Enable(unsigned int EXTI_NUM,unsigned int PortID){
	(*SYSCFG_EXTICR1) &=(0x00 << 0x00);
}

// ####################################################
void GPIO_EnableClock(unsigned int PortID)
{
	*RCC_AHB1ENR |= (0x01 << PortID);
}

void GPIO_Init(unsigned int PortID, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState)
{
	//MODER
	*Lookup[PortID][0] &= ~(0x03 << 2 * PinNum);
	*Lookup[PortID][0] |= PinMode << 2 * PinNum;

	//OTYPER
	*Lookup[PortID][1] &= ~(1 << PinNum);
	*Lookup[PortID][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

	//PUPDR
	*Lookup[PortID][3] &= ~(0x03 << 2 * PinNum);
	*Lookup[PortID][3] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned int PortID, unsigned char PinNum,
                            unsigned char Data)
	{

		unsigned char result;
	    if (((*Lookup[PortID][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
	      if (Data) {
	    	  *Lookup[PortID][5] |= (1 << PinNum);
	      } else {
	    	  *Lookup[PortID][5] &= ~(1 << PinNum);
	      }
	      result = OK;
	    } else {
	      result = NOK;
	    }

	    return result;
	}

unsigned char GPIO_ReadPin(unsigned int PortID, unsigned char PinNum)
	{
		unsigned char data = 0;
		data = (*Lookup[PortID][4] & (1 << PinNum)) >> PinNum;
		return data;
	}
