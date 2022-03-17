/*
 * Author: Radwa_Saeed
 * Date   : 13/1/2022
 * Version: 1.0.0
 */
#include "SPI.h"

#include "GPIO.h"
#include "SPI_REGs.h"
#include "stm32f401xc.h"

#define SPI1_RCC_EN() (RCC->APB2ENR |= RCC_APB2ENR_SPI1EN)
#define SPI1_AF_EN() (GPIOA->AFR[0] |= 0x555 << (5 * 4))

void SPI1_Init(unsigned char MasterSlave, unsigned char ClkPol, unsigned char ClkPhase) {

  SPI1_RCC_EN();

  GPIO_EnableClock(0);
  GPIO_Init(0, 5, ALTERNATE_FUN, PUSH_PULL);
  GPIO_Init(0, 6, ALTERNATE_FUN, PUSH_PULL);
  GPIO_Init(0, 7, ALTERNATE_FUN, PUSH_PULL);
  SPI1_AF_EN();


  SPI1_CR1 |= (0x3 << SPI_CR1_SSI_Pos);

  SPI1_CR1 &= ~(1 << SPI_CR1_MSTR_Pos);
  SPI1_CR1 |= (MasterSlave << SPI_CR1_MSTR_Pos);

  SPI1_CR1 &= ~(1 << SPI_CR1_CPOL_Pos);
  SPI1_CR1 |= (ClkPol << SPI_CR1_CPOL_Pos);

  SPI1_CR1 &= ~(1 << SPI_CR1_CPHA_Pos);
  SPI1_CR1 |= (ClkPhase << SPI_CR1_CPHA_Pos);

  /*************************************************************************/
  // Baud Rate
  SPI1_CR1 &= ~(0x7 << SPI_CR1_BR_Pos);
  SPI1_CR1 |= (0x3 << SPI_CR1_BR_Pos);  // 16/16 -> 1MHZ
  /*************************************************************************/

  SPI1_CR1 |= (1 << SPI_CR1_SPE_Pos);
}

unsigned char SPI1_TransmitRecieveByte(unsigned char TxData) {
  if (SPI1_SR & (1 << SPI_SR_TXE_Pos)) {
    SPI1_DR = TxData;
    while (SPI1_SR & (1 << SPI_SR_BSY_Pos));
    return SPI1_DR;
  }
  return -1;
}
