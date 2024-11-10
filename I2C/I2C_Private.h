/*
 * I2C_Private.h
 *
 *  Created on: Jun 13, 2023
 *      Author: saids
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#include "STD_TYPES.h"

#define I2C_1_BASE_ADREESS  0x40005400
#define I2C_2_BASE_ADREESS  0x40005800

typedef struct{

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 OAR1;
	volatile u32 OAR2;
	volatile u32 DR;
	volatile u32 SR1;
	volatile u32 SR2;
	volatile u32 CCR;
	volatile u32 TRISE;



}I2C_t;

#endif /* I2C_PRIVATE_H_ */
