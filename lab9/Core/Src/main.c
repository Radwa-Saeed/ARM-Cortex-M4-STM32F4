/*
 * Author: Radwa_Saeed
 * Date   : 7/12/2021
 * Version: 1.0.0
 */

#include "GPIO.h"
#include "I2C.h"
#include "RTC.h"
#include "SPI.h"
#include "TC72.h"
#include "USART.h"
#include "Util.h"
#include "stm32f401xc.h"

#define TC72_SELECT()   (GPIO_WritePin(1, 0, 1))
#define TC72_UNSELECT() (GPIO_WritePin(1, 0, 0))

void floatToStr(float val, char data[]);
void timeToStr(unsigned char time[], char data[]);

int main(void) {
  char usart2TempData[] = {'-', ' ', ' ', '.', ' ', ' ', '\r', '\n', '\0'};
  char usart2TimeData[] = {' ', ' ', ':', ' ', ' ', ':',' ', ' ', '\r', '\n', '\0'};
  unsigned char spiData = 0;
  float temperature = 0;
  unsigned char buffer[3] = {0};

  /* Slave Select */
  GPIO_EnableClock(1);
  GPIO_Init(1, 0, OUTPUT, PUSH_PULL);
  GPIO_WritePin(1, 0, 0);

  USART2_Init();
  USART2_Transmit("Hello SPI I2C\r\n");
  SPI1_Init(MASTER, IDLE_LOW, SAMPLE_SOCAND_TRANSITION);


  GPIO_Init(1, 1, OUTPUT, PUSH_PULL);
  I2C1_Init();
  RTC_Init();

  TC72_SELECT();
  TC72_Init(0);
  TC72_UNSELECT();
  
  while (1) {
    temperature = 0.0f;
    TC72_SELECT();
    TC72_RegisterRead(0x01, &spiData);
    TC72_UNSELECT();

    if (spiData & (1 << 7)) {
      temperature += 0.5f;
    }
    if (spiData & (1 << 6)) {
      temperature += 0.25f;
    }

    TC72_SELECT();
    TC72_RegisterRead(0x02, &spiData);
    TC72_UNSELECT();

    temperature += (signed char)spiData;

    floatToStr(temperature, usart2TempData);
    USART2_Transmit(usart2TempData);

    // RTC_GetTime(&buffer[0], &buffer[1], &buffer[2]);
    // timeToStr(buffer, usart2TimeData);
    // USART2_Transmit(usart2TimeData);
  }
  return 0;
}

#define CHAR(x)  ((x) + '0')

void floatToStr(float val, char data[]) {
  if (val < 0) {
    *data = '-';
    data++;
    val *= -1;
  }
  int intVal = val * 100;
  data[4] = (intVal % 10) + '0';
  intVal /= 10;
  data[3] = (intVal % 10) + '0';
  data[2] = '.';
  intVal /= 10;
  data[1] = (intVal % 10) + '0';
  intVal /= 10;
  data[0] = (intVal % 10) + '0';

  data[5] = '\r';
  data[6] = '\n';
  data[7] = '\0';
}

void timeToStr(unsigned char time[], char data[]){
  data[0] = CHAR((time[0]) >> 4);
  data[1] = CHAR((time[0]) & 0x0F);

  data[3] = CHAR((time[1]) >> 4);
  data[4] = CHAR((time[1]) & 0x0F);

  data[6] = CHAR((time[3]) >> 4);
  data[7] = CHAR((time[3]) & 0x0F);
}
