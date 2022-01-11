/*
 * EXTI.h
 *
 *  Created on: Dec 29, 2021
 *      Author: Radwa_Saeed
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#define EXTI_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID + REG_ID))
// CLOCK SYS_CONFIG REGISTER (RCC = 0x4002 3800 )
# define RCC_APB2ENR 	(EXTI_REG(0x40023800,0x44))

// SYS CONFIG EXTERNAL INTERRUPT REGISTERS (SYSCFG = 0x4001 3800 )
# define SYSCFG_EXTICR1 (EXTI_REG(0x40013800,0x08))
# define SYSCFG_EXTICR2 (EXTI_REG(0x40013800,0x0C))
# define SYSCFG_EXTICR3 (EXTI_REG(0x40013800,0x10))
# define SYSCFG_EXTICR4 (EXTI_REG(0x40013800,0x14))

// EXT INT REGISTERS (EXTI = 0x4001 3C00)
# define EXTI_IMR 	(EXTI_REG(0x40013C00 ,0x00))
# define EXTI_EMR 	(EXTI_REG(0x40013C00 ,0x04))
# define EXTI_RTSR 	(EXTI_REG(0x40013C00 ,0x08))
# define EXTI_FTSR 	(EXTI_REG(0x40013C00 ,0x0C))
# define EXTI_SWIER (EXTI_REG(0x40013C00 ,0x10))
# define EXTI_PR 	(EXTI_REG(0x40013C00 ,0x14))
// NVIS (0xE000E100)
# define NVIC_ISER0	(EXTI_REG(0xE000E100 ,0x00))
# define NVIC_ISER1	(EXTI_REG(0xE000E100 ,0x04))
# define NVIC_ISER2	(EXTI_REG(0xE000E100 ,0x08))
# define NVIC_ISER3	(EXTI_REG(0xE000E100 ,0x0C))


void EXTI_EnableClock(void);
void EXIT_INIT(char Port, int EXTx, char state);

/* EXTI options: */
#define EXTI0 0
#define EXTI1 1
#define EXTI2 2
#define EXTI3 3

/* state options: */
#define FALLING 1
#define RISSING 2

#define FALLING_MASK(state)  (state&1)
#define RISING_MASK(state) ((state>>1) & 1)

#endif /* INC_EXTI_H_ */
