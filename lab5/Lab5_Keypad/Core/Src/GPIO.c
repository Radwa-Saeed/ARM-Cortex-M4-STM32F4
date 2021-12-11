/*
 * Author : Radwa Saeed
 * Date   : 7/12/2021
 * Version: 1.0.0
 */

#include "GPIO.h"

#include "stm32f401cc_interface.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

void GPIO_EnableClock(char PortName) {
  switch (PortName) {
    case 'A':
      RCC_AHB1ENR |= (0x01 << 0);
      break;
    case 'B':
      RCC_AHB1ENR |= (0x01 << 1);
      break;
    default:
      break;
  }
}

void GPIO_Init(char PortName, unsigned char PinNum, unsigned char PinMode,unsigned char DefaultState) {
  switch (PortName) {
    case ('A'):
      // Configure moder register for pin direction
      GPIOA_MODER &= ~(0x03 << 2 * PinNum);
      GPIOA_MODER |= PinMode << 2 * PinNum;

      GPIOA_OTYPER &= ~(1 << PinNum);
      GPIOA_OTYPER |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      GPIOA_PUPDR &= ~(0x03 << 2 * PinNum);
      GPIOA_PUPDR |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
      break;
    case ('B'):
      // Configure moder register for pin direction
      GPIOB_MODER &= ~(0x03 << 2 * PinNum);
      GPIOB_MODER |= PinMode << 2 * PinNum;

      GPIOB_OTYPER &= ~(1 << PinNum);
      GPIOB_OTYPER |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      GPIOB_PUPDR &= ~(0x03 << 2 * PinNum);
      GPIOB_PUPDR |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
      break;
  }
}

unsigned char GPIO_WritePin(char PortName, unsigned char PinNum,unsigned char Data) {
  unsigned char result;
  switch (PortName) {
    case ('A'):
      if (((GPIOA_MODER & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
          GPIOA_ODR |= (1 << PinNum);
        } else {
          GPIOA_ODR &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }
      break;
    case ('B'):
      if (((GPIOB_MODER & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
          GPIOB_ODR |= (1 << PinNum);
        } else {
          GPIOB_ODR &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }
      break;
    default:
      result = NOK;
      break;
  }  // end switch

  return result;
}

unsigned char GPIO_ReadPin(char PortName, unsigned char PinNum) {
  unsigned char data = 0;
  switch (PortName) {
    case 'A':
      data = (GPIOA_IDR & (1 << PinNum)) >> PinNum;
      break;
    case 'B':
      data = (GPIOB_IDR & (1 << PinNum)) >> PinNum;
      break;
    default:
      break;
  }
  return data;
}
