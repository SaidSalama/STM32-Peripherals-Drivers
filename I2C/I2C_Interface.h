/*
 * I2C_Interface.h
 *
 *  Created on: Jun 13, 2023
 *      Author: saids
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum
{
	I2C_1,
	I2C_2

}I2C_NUM;

typedef enum
{
	I2C_DISABLE,
	I2C_ENABLE

}I2C_State;

typedef enum
{
	I2C_Mode,
	SMBUS_Mode

}I2C_MODE;

typedef enum
{
	_0MHz=0,			//not allowed
	_1MHz=1,			//not allowed
	_8MHz=8,
	/****continue the same way**********/
	_50MHz=50


}CLCK_Freq;

typedef enum
{
	_7BIT_Adressing_Mode,
	_10BIT_Adressing_Mode

}Addresing_Mode;

typedef enum
{
	Receiver,
	Transmitter

}Direction;
typedef struct{
	I2C_NUM  I2C_Num;
	I2C_State ACKnowledge;
	I2C_State CLCK_Stretching;
	I2C_State General_Call;
	I2C_MODE  Mode;
	CLCK_Freq BUS_Frequency;
	I2C_State  DMA_requests;
	I2C_State  Buffer_interrupt ;
	I2C_State   Event_interrupt ;
	I2C_State	Dual_Addressing_Mode;
	Addresing_Mode Addresing_Mode;
	u32 	Primary_Slave_Address;					//write this address in OAR1
	u32 	Secondary_Slave_Address;				//write this address in OAR2 if dual addressing mode is enable
	u32		I2C_Frequency;							//this is used to calculate the CCR value --> CCR=(T_high/T_pclck)	or CCR = (BUS_Frequency*1000000/2*I2C_Frequency)
	u32		I2C_RiseTime;							//configuration of TRISE register --->  TRISE=(rise time / T_pclck)+1   ----- time in microsecond
}I2C_Config;


#endif /* I2C_INTERFACE_H_ */
