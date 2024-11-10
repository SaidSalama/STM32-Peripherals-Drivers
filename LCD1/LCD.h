/*
 * LCD.h
 *
 *  Created on: Oct 6, 2022
 *      Author: Said Salama
 */



#include "Std_Types.h"
#include "BIT_MATH.h"

#ifndef INC_LCD_H_
#define INC_LCD_H_

/* List of COMMANDS */
#define LCD_CLEARDISPLAY      0x01
#define LCD_RETURNHOME        0x02
#define LCD_ENTRYMODESET      0x04
#define LCD_DISPLAYCONTROL    0x08
#define LCD_CURSORSHIFT       0x10
#define LCD_FUNCTIONSET       0x20
#define LCD_SETCGRAMADDR      0x40
#define LCD_SETDDRAMADDR      0x80

/* List of commands Bitfields */
//1) Entry mode Bitfields
#define LCD_ENTRY_SH          0x01
#define LCD_ENTRY_ID          0x02
//2) Entry mode Bitfields
#define LCD_ENTRY_SH          0x01
#define LCD_ENTRY_ID          0x02
//3) Display control
#define LCD_DISPLAY_B         0x01
#define LCD_DISPLAY_C         0x02
#define LCD_DISPLAY_D         0x04
//4) Shift control
#define LCD_SHIFT_RL          0x04
#define LCD_SHIFT_SC          0x08
//5) Function set control
#define LCD_FUNCTION_F        0x04
#define LCD_FUNCTION_N        0x08
#define LCD_FUNCTION_DL       0x10

#define RS 1   //the pin connected to RS
#define E  3	// pin connected to E

#define DATA_PORT GPIOA  		//port to which data pins of lcd are connected
#define CMND_PORT GPIOA		//port to which RS and E are connected

/* declarations of functions used for lcd*/
void LCD_Init_Commands();
void LCD_Init_GPIO();
void LCD_Write(u8 wbyte);
void LCD_Enable_Pulse();
void LCD_Command(u8 cmnd);
void LCD_Data(u8 data);
void LCD_Print(u8 *sentence);

#endif  /* INC_LCD_H_ */
