/*
 * I2C.c
 *
 *  Created on: Jun 13, 2023
 *      Author: saids
 */
#include "I2C_Private.h"
#include "I2C_Interface.h"
#include "STD_TYPES.h"
#include"RCC_Interface.h"

I2C_t* I2C_x[2]={
		( I2C_t*)I2C_1_BASE_ADREESS,
		( I2C_t*)I2C_2_BASE_ADREESS
};

void I2C_Init(I2C_Config* I2C_Config)
{
	/*enable the peripheral clock*/
	if(I2C_Config->I2C_Num ==I2C_1)
	{
		RCC_PerClock_State(APB1, I2C1_PERIPHERAL, PClock_enable);
	}
	else if(I2C_Config->I2C_Num ==I2C_2)
	{
		RCC_PerClock_State(APB1, I2C2_PERIPHERAL, PClock_enable);
	}

	/*reset the I2C peripheral*/
	I2C_x[I2C_Config->I2C_Num]->CR1|=(1<<15);
	I2C_x[I2C_Config->I2C_Num]->CR1 &= ~(1<<15);

	/*Peripheral Frequency and rise time */
	// To configure clock I2C must be disabled
	I2C_x[I2C_Config->I2C_Num]->CR1 &= ~(1<<0);							//disable I2C
	I2C_x[I2C_Config->I2C_Num]->CCR |= (u32)((I2C_Config->BUS_Frequency*1000000)/(2*I2C_Config->I2C_Frequency));
	I2C_x[I2C_Config->I2C_Num]->CR2|=(I2C_Config->BUS_Frequency*1000000<<0);
	I2C_x[I2C_Config->I2C_Num]->TRISE=(u32)(I2C_Config->I2C_RiseTime*I2C_Config->BUS_Frequency)+1;  //the time should be divided by 1000000 to be in micro but the frequency should be multiplied by same value so we don't write them

	/*configurations of CR1*/
	I2C_x[I2C_Config->I2C_Num]->CR1|=(I2C_Config->ACKnowledge<<10);
	I2C_x[I2C_Config->I2C_Num]->CR1|=(I2C_Config->General_Call<<6);
	I2C_x[I2C_Config->I2C_Num]->CR1|=(I2C_Config->Mode<<1);
	I2C_x[I2C_Config->I2C_Num]->CR1|=(I2C_Config->CLCK_Stretching<<7);

	/*configurations of OAR1 & OAR2*/
	I2C_x[I2C_Config->I2C_Num]->OAR2|=(I2C_Config->Dual_Addressing_Mode<<0);
	I2C_x[I2C_Config->I2C_Num]->OAR1|=(I2C_Config->Addresing_Mode<<15);
	I2C_x[I2C_Config->I2C_Num]->OAR1|=(I2C_Config->Primary_Slave_Address<<1);
	if(I2C_Config->Dual_Addressing_Mode==1)
	{
		I2C_x[I2C_Config->I2C_Num]->OAR2|=(I2C_Config->Secondary_Slave_Address<<1);
	}

	/*enable interrupts and DMA*/
	/*
	 *
	 */
	/*enable I2C*/
	I2C_x[I2C_Config->I2C_Num]->CR1|=(1<<0);

}
void I2C_Write_Data(I2C_Config* I2C_Config,u8 Data)
{
	I2C_x[I2C_Config->I2C_Num]->CR1|=(1<<8);				//start bit in CR1 to generate start condition
	while (!(I2C_x[I2C_Config->I2C_Num]->SR1 & (1<<0)));  // wait for SB bit to set
	while (!(I2C_x[I2C_Config->I2C_Num]->SR1 & (1<<7)));  // wait for TXE bit to set
	I2C_x[I2C_Config->I2C_Num]->DR = Data;
	while (!(I2C_x[I2C_Config->I2C_Num]->SR1 & (1<<2)));  // wait for BTF bit to set
}

void Master_I2C_Write_Address(I2C_Config* I2C_Config, u8 Address, Direction Direction)			//write address in 7bit mode
{
	Address=(Address<<1);			//left shift the address so it becomes 7bits and lsb t be 0
	if(Address==Receiver)
	{
		Address|=(1<<0);			//set the lsb of address to be in receiver mode
	}
	else if(Address==Transmitter)
	{
		Address&= ~(1<<0);			//reset the lsb of address to be in transmitter mode
	}

	I2C_x[I2C_Config->I2C_Num]->DR = Address;  //  send the address
	while (!(I2C_x[I2C_Config->I2C_Num]->SR1 & (1<<1)));  // wait for ADDR bit to set
	u8 temp = I2C_x[I2C_Config->I2C_Num]->SR1 | I2C_x[I2C_Config->I2C_Num]->SR2; // read SR1 and SR2 to clear the ADDR bit
}

I2C_Enable_Disable_ACKnowledge(I2C_Config* I2C_Config,I2C_State State)
{
	if(State==I2C_DISABLE)
	{
		I2C_x[I2C_Config->I2C_Num]->CR1  &= ~(1<<10);
	}
	else if(State==I2C_ENABLE)
	{
		I2C_x[I2C_Config->I2C_Num]->CR1  |= (1<<10);
	}
}

void Master_I2C_Generate_Start(I2C_Config* I2C_Config)
{
	I2C_x[I2C_Config->I2C_Num]->CR1|=(1<<8);
}

void Master_I2C_Generate_Stop(I2C_Config* I2C_Config)
{
	I2C_x[I2C_Config->I2C_Num]->CR1 &= ~(1<<8);
}





