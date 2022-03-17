
/*
 * Author: Radwa_Saeed
 * Date   : 15/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"

#include "Util.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

#define _SPEED_MASK ((unsigned char)0x18)
#define _SPEED_SHIFT 3


#define GPIOA_ADDR                (0x40020000)
#define GPIOB_ADDR                (0x40020400)




unsigned int PortAddresses[2] = {GPIOA_ADDR, GPIOB_ADDR};

#define GPIO_MODER(ID)            DEF_REG(PortAddresses[ID], 0x00)
#define GPIO_TYPER(ID)            DEF_REG(PortAddresses[ID], 0x04)
#define GPIO_OSPEEDR(ID)          DEF_REG(PortAddresses[ID], 0x08)
#define GPIO_PUPDR(ID)            DEF_REG(PortAddresses[ID], 0x0C)
#define GPIO_IDR(ID)              DEF_REG(PortAddresses[ID], 0x10)
#define GPIO_ODR(ID)              DEF_REG(PortAddresses[ID], 0x14)
#define GPIO_BSRR(ID)             DEF_REG(PortAddresses[ID], 0x18)
#define GPIO_LCRR(ID)             DEF_REG(PortAddresses[ID], 0x1C)
#define GPIO_AFRL(ID)             DEF_REG(PortAddresses[ID], 0x20)
#define GPIO_AFRH(ID)             DEF_REG(PortAddresses[ID], 0x24)


#define RCC_AHB1ENR               DEF_REG(0x40023800, 0x30)

void GPIO_EnableClock(unsigned char Port_id) {
  if (Port_id == 0) {
    RCC_AHB1ENR |= (1 << 0);
  } else if (Port_id == 1) {
    RCC_AHB1ENR |= (1 << 1);
  }
}

void GPIO_Init(unsigned char PortId, unsigned char PinNum,
               unsigned char PinMode, unsigned char DefaultState) {
  GPIO_MODER(PortId) &= ~(0x03 << 2 * PinNum);
  GPIO_MODER(PortId) |= PinMode << 2 * PinNum;

  GPIO_TYPER(PortId) &= ~(1 << PinNum);
  GPIO_TYPER(PortId) |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

  GPIO_PUPDR(PortId) &= ~(0x03 << 2 * PinNum);
  GPIO_PUPDR(PortId) |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);

  GPIO_OSPEEDR(PortId) &= ~(0x03 << 2 * PinNum);
  GPIO_OSPEEDR(PortId) |= ((DefaultState & _SPEED_MASK) >> _SPEED_SHIFT) << (2 * PinNum);

}

unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum,
                            unsigned char Data) {
  unsigned char result;

  if (((GPIO_MODER(PortId) & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
    if (Data) {
      GPIO_ODR(PortId) |= (1 << PinNum);
    } else {
      GPIO_ODR(PortId) &= ~(1 << PinNum);
    }
    result = OK;
  } else {
    result = NOK;
  }

  return result;
}

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum) {
  unsigned char data = 0;

  data = (((GPIO_IDR(PortId)) & (1 << PinNum)) >> PinNum);
  return data;
}
