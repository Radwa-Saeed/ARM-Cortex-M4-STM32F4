#include "GPIO.h"
#include "stm32f401xc.h"

void USART2_Init(void) {
  GPIO_EnableClock(0);
  GPIO_Init(0, 2, ALTERNATE_FUN, PUSH_PULL);

  GPIOA->AFR[0] &= ~(0xf << 4 * 2);
  GPIOA->AFR[0] |= 0x7 << 4 * 2;


  RCC->APB1ENR |= 1 << RCC_APB1ENR_USART2EN_Pos;

  USART2->CR1 &= ~(1 << USART_CR1_M_Pos);

  USART2->CR2 &= ~(USART_CR2_STOP);

  USART2->CR1 &= ~(1 << USART_CR1_OVER8_Pos);

  USART2->BRR = 0x683;  // Baud Rate 9600

  /* Enable Transmission block */
  USART2->CR1 |= (1 << USART_CR1_TE_Pos);

  // /* Enable Receive block */
  // USART2->CR1 |= (1 << USART_CR1_RE_Pos);

  /* Enable USART2 */
  USART2->CR1 |= (1 << USART_CR1_UE_Pos);
}

void USART2_Transmit(const char* Str) {
  unsigned char i = 0;
  while (Str[i] != '\0') {
    if (USART2->SR & USART_SR_TXE) {
      USART2->DR = Str[i];
      while (!(USART2->SR & USART_SR_TC));
      USART2->SR &= ~(1 << USART_SR_TC_Pos);  // Clearing TC bit
      i++;
    }
  }
}
