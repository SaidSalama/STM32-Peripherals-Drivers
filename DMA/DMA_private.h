/*
 * DMA_private.h
 *
 *  Created on: Aug 28, 2022
 *      Author: Said Salama
 */

#ifndef MCAL_DMA_DMA_PRIVATE_H_
#define MCAL_DMA_DMA_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

#define DMA1_BASE_ADDRES  0x40020000
#define DMA2_BASE_ADDRES  0x40020400

typedef struct{

	volatile u32 CRR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;

}DMA_Channel;

typedef struct{

	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7] ;
}DMA_t;


/*DMA_t *DMAx [2] = {
    (DMA_t *)DMA1_BASE_ADDRES,
    (DMA_t *)DMA2_BASE_ADDRES
};*/


/* *****************************************************************************
* Variables
*******************************************************************************/


#endif /*File_H_*/

/*** End of File **************************************************************/


