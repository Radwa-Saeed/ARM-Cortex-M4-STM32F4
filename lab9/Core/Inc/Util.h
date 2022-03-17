/*
 * Author: Radwa_Saeed
 * Date   : 22/12/2021
 * Version: 1.0.0
 */

#ifndef UTIL_H
#define UTIL_H

#define DEF_REG(PORT_ID, REG_ID) (*((unsigned int *)(PORT_ID + REG_ID)))

void delay_ms(unsigned short ms);

#define NVIC_ISER0 DEF_REG(0xE000E100, 0x00)

#define NVIC_ICER0 DEF_REG(0xE000E100, 0x180)

#endif /* UTIL_H */
