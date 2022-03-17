#include "Util.h"


void delay_ms(unsigned short ms) {
  unsigned int i;
  while (ms) {
    for (i = 0; i < 1000; i++) {
    }
    ms--;
  }
}