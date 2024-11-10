/*
 * LCD.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Said Salama
 */
/*this file is copy of the LCD1602.c file but with my IO function*/

#include "LCD.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "DIO_interface.h"
#include "DIO_private.h"
#include "RCC_interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../SYSTK/STK_interface.h"


void LCD_Init_GPIO()
{
	  RCC_PerClock_State(APB2, IOPA_PERIPHERAL, PClock_enable);			//enable portA
	 for(int i=1;i<8;i++)
	 {
		 DIO_PinMode(GPIOA,i,OUTPUT_SPEED_50MHZ_PP);			//portA output
	 }
}

void LCD_Init_Commands()			/*WE MUST INITIALIZE GPIO BEFORE COMMANDS*/
{

	// 4 bit initialisation
	//HAL_Delay(5);  // wait for >40ms
	MSTK_voidSetBusyWait(5000);
	LCD_Command (0x30);
	//HAL_Delay(5);  // wait for >4.1ms
	MSTK_voidSetBusyWait(5000);
	LCD_Command (0x30);
	//HAL_Delay(1);  // wait for >100us
	MSTK_voidSetBusyWait(1000);
	LCD_Command (0x30);
	//HAL_Delay(10);
	MSTK_voidSetBusyWait(10000);
	LCD_Command (0x20);  // 4bit mode
	//HAL_Delay(10);
	MSTK_voidSetBusyWait(10000);

  // dislay initialisation
	LCD_Command (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	//HAL_Delay(1);
	MSTK_voidSetBusyWait(1000);
	LCD_Command (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	//HAL_Delay(1);
	MSTK_voidSetBusyWait(1000);
	LCD_Command (0x01);  // clear display
	//HAL_Delay(1);
	MSTK_voidSetBusyWait(1000);
	//HAL_Delay(1);
	MSTK_voidSetBusyWait(1000);
	LCD_Command (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	//HAL_Delay(1);
	MSTK_voidSetBusyWait(1000);
	LCD_Command (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)

}

void LCD_Write(u8 data)
{
	//HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, rs);  // rs = 1 for data, rs=0 for command

	/* write the data to the respective pin */
	DIO_PinWrite(GPIOA, 7, ((data>>3)&0x01));
	DIO_PinWrite(GPIOA, 6, ((data>>2)&0x01));
	DIO_PinWrite(GPIOA, 5, ((data>>1)&0x01));
	DIO_PinWrite(GPIOA, 4, ((data>>0)&0x01));

	/* Toggle EN PIN to send the data
	 * if the HCLK > 100 MHz, use the  20 us delay
	 * if the LCD still doesn't work, increase the delay to 50, 80 or 100..
	 */
	DIO_PinWrite(GPIOA, 3, GPIO_HIGH);
	//delay (20);
	MSTK_voidSetBusyWait(20);
	DIO_PinWrite(GPIOA, 3, GPIO_LOW);
	//delay (20);
	MSTK_voidSetBusyWait(20);
	//LCD_Enable_Pulse();

}

void LCD_Enable_Pulse()
{
	    DIO_PinWrite(CMND_PORT, 3,GPIO_HIGH);
	    MSTK_voidSetBusyWait(20);
		DIO_PinWrite(CMND_PORT, 3,GPIO_LOW);
		MSTK_voidSetBusyWait(20);
}

void LCD_Command(u8 cmd)
{
	DIO_PinWrite(GPIOA, 1,GPIO_LOW);		//RS=0 to send command
    u8 datatosend;

    /* send upper nibble first */
    datatosend = ((cmd>>4)&0x0f);
    LCD_Write(datatosend); 				 // RS must be 0 while sending command

    /* send Lower Nibble */
    datatosend = ((cmd)&0x0f);
    LCD_Write(datatosend);
	//LCD_Enable_Pulse();
}

void LCD_Data(u8 data)
{
	DIO_PinWrite(GPIOA, 1,GPIO_HIGH);			//RS=1 to send data
    u8 datatosend;

    /* send upper nibble first */
    datatosend = ((data>>4)&0x0f);
    LCD_Write(datatosend); 				 // RS must be 1 while sending DATA

    /* send Lower Nibble */
    datatosend = ((data)&0x0f);
    LCD_Write(datatosend);
	//LCD_Enable_Pulse();
}
void LCD_Print(u8* sentence)
{
	u8 i=0;
	while(sentence[i]!=0)
	{
		LCD_Data(sentence[i]);
		i++;
	}
}

