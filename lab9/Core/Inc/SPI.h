/*
 * Author: Radwa_Saeed
 * Date   : 13/1/2022
 * Version: 1.0.0
 */

#ifndef SPI_H
#define SPI_H


/* Master or Slave */
#define SLAVE  0
#define MASTER 1

/* Clock Polarity */
#define IDLE_LOW  0
#define IDLE_HIGH 1

/* Clock Phase */
#define SAMPLE_FIRST_TRANSITION  0 // Read or Capture on first transition
#define SAMPLE_SOCAND_TRANSITION 1 

void SPI1_Init(unsigned char MasterSlave, unsigned char ClkPol, unsigned char ClkPhase);


/**
 * 
 * @param TxData Byte to be transmitted 
 * @return Recieved Date
 */

unsigned char SPI1_TransmitRecieveByte(unsigned char TxData);


#endif /* SPI_H */
