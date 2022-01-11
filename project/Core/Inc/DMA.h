/*
 * DMA.h
 *
 *  Created on: Jan 4, 2022
 *      Author: Radwa_Saeed
 */
#ifndef INC_DMA_H_
#define INC_DMA_H_

#define DMA_REG(BASE,OFFSET) *(unsigned int*)(BASE + OFFSET)

// ########## WORKING ON DMA2 ON BUS AHB1 ##########
//#define RCC_AHB1ENR 	(DMA_REG(0x40023800,0x30))

// ########## DMA2 REGISTERS (BASE = 0x40026400) OF STREAM 0 ##########
#define DMA1_BASE (0x40026000)
#define DMA2_BASE (0x40026400)

#define  DMA2_LISR 		(DMA_REG(DMA2_BASE, 0x0000))
#define  DMA2_HISR 		(DMA_REG(DMA2_BASE, 0x0004))
#define  DMA2_LIFCR 	(DMA_REG(DMA2_BASE, 0x0008))
#define  DMA2_HIFCR 	(DMA_REG(DMA2_BASE, 0x000C))
#define  DMA2_S0CR 		(DMA_REG(DMA2_BASE, 0x0010))
#define  DMA2_S0NDTR 	(DMA_REG(DMA2_BASE, 0x0014))
#define  DMA2_S0PAR 	(DMA_REG(DMA2_BASE, 0x0018))
#define  DMA2_S0MAR 	(DMA_REG(DMA2_BASE, 0x001C))
#define  DMA2_S0FCR 	(DMA_REG(DMA2_BASE, 0x0024))

// DMAx Selection
#define DMA1_EN 21
#define DMA2_EN 22
//
#define DMA_EN 	1
#define DMA_DISEN 0

#define DMA_DIR_PM 0
#define DMA_DIR_MP 1
#define DMA_DIR_MM 2

#define DMA_DATA_BYTE  0
#define DMA_DATA_HWORD 1
#define DMA_DATA_WORD 2

#define DMA_TCIE_DISEN 0
#define DMA_TCIE_EN 1

#define DMA_FIFO_QUART 0
#define DMA_FIFO_HALF 1
#define DMA_FIFO_TQUART 2
#define DMA_FIFO_FULL 3

void DMA_EnableClock(unsigned char DMA_Num);
void DMA2_Stream0_Config(char DIR, char PSIZE,char MSIZE, char PINC, char MINC, char TCIE,char FIFO);
void DMA2_Stream0_Set_Addresses( unsigned int* src, unsigned int* dst);
void DMA2_Stream0_Enable(unsigned int items_no);
void DMA2_Stream0_IntClr(void);

#endif /* INC_DMA_H_ */
