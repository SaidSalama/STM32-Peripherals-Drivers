/*
 * Timer1.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Said Salama
 */

#include <timer1_private.h>
#include <Timer1_config.h>
#include <Timer1_interface.h>
#include "RCC_interface.h"
#include "Std_Types.h"
#include "BIT_MATH.h"
//#include "stm32f1xx.h"
#include "DIO_interface.h"



 TIMER_t *Timer_Num [2] = {
    Timer1,
	Timer2
};

/*void Timer1_Init(Timer_Config* Timer1Config)
{*/
	/*TIMER1 BASIC CONFIG*/
/*	RCC_PerClock_State(APB2 ,11 ,PClock_enable );   								//enable timer1 clock
	Timer1->PSC=7;												  					 //time base =1ms
	Timer1->ARR=0xffff;																	//period in ms
	Timer1->CR1|=((Timer1Config->Auto_Reload_Preload)<<7);							// enable or disable auto reload
	Timer1->CR1|=((Timer1Config->Center_Aligned_mode)<<5);							//select center aligned mode
	Timer1->CR1|=((Timer1Config->Counter_Direction)<<4);	*/						//up counting or down counting
				/***********CH1***********/
/*	if(Timer1Config->Ch1==CH_Used)														//this configuration is for channel 1
	{
		Timer1->CCMR1|=((Timer1Config->Ch1_Dir)<<0);								//direction of channel1
		if(Timer1Config->Ch1_Dir==Output)
		{
			Timer1->CCMR1|=((Timer1Config->Ch1_OutputCompare_Preload)<<3);		    //enable or disable preload
			Timer1->CCMR1|=((Timer1Config->Ch1_Output_Compare_mode)<<4);			//chanel output mode
			Timer1->CCER |= ((Timer1Config->Ch1_Polarity)<<1);						//polarity selection ch1
			Timer1->CCR1 = 35;				                                    //duty cycle of ch1 35/40
			Timer1->BDTR|=(1<<15)|(1<<10);											//enable OC pin MOE pin
			Timer1->CCER |= (1<<0);													//enable capture compare ch1
		}
		else if (Timer1Config->Ch1_Dir==Input_Ic1_On_Tl1)
		{
			Timer1->CCMR1|=((Timer1Config->Ch1_Input_Filter)<<4);                   //selecting the input fiter
			Timer1->CCMR1|=((Timer1Config->Ch1_Input_PSC)<<2);						//selecting the input prescaler
			Timer1->CCER|=((Timer1Config->Ch1_Input_Edge)<<1);						//rising or falling
			Timer1->CCER |= (1<<0);													//enable capture compare ch1
		}
	}*/

					/********************/
	/***********CH2***********/
/*	 if(Timer1Config->Ch2==CH_Used)											//this configuration is for channel 2
	{
		 Timer1->CCMR1|=((Timer1Config->Ch2_Dir)<<8);							//direction of channel2
		 if(Timer1Config->Ch2_Dir==Output)
		 	 {
				Timer1->CCMR1|=((Timer1Config->Ch2_OutputCompare_Preload)<<11);		//enable or disable preload
				Timer1->CCMR1|=((Timer1Config->Ch2_Output_Compare_mode)<<12);			//chanel output mode
				Timer1->CCER|=((Timer1Config->Ch2_Polarity)<<5);						//polarity selection ch2
				Timer1->CCR2=(35);												  //duty cycle of ch2=100%
				Timer1->BDTR|=(1<<15)|(1<<10);											//enable OC pin MOE
				Timer1->CCER|=(1<<4);												//enable capture compare ch2
		 	 }
		 else if (Timer1Config->Ch2_Dir==Input_Ic1_On_Tl1)
			{
				Timer1->CCMR1|=((Timer1Config->Ch2_Input_Filter)<<12);                   //selecting the input fiter
				Timer1->CCMR1|=((Timer1Config->Ch2_Input_PSC)<<10);						//selecting the input prescaler
				Timer1->CCER|=((Timer1Config->Ch2_Input_Edge)<<5);						//rising or falling
				Timer1->CCER |= (1<<4);													//enable capture compare ch1
			}

		}*/

		/********************/
/***********CH3***********/
/*	 if(Timer1Config->Ch3==CH_Used)													//this configuration is for channel 3
	{
		Timer1->CCMR2|=(Timer1Config->Ch3_Dir<<0);									//direction of channel3
		if(Timer1Config->Ch3_Dir==Output)
		{
				Timer1->CCMR2|=((Timer1Config->Ch3_OutputCompare_Preload)<<3);				//enable or disable preload
					Timer1->CCMR2|=((Timer1Config->Ch3_Output_Compare_mode)<<4);			//chanel output mode
					Timer1->CCER|=((Timer1Config->Ch3_Polarity)<<9);						//polarity selection ch3
					Timer1->CCR3=((TIMER1_Ch3_DutyCycle*Timer1->ARR/100));					//duty cycle of ch3
					Timer1->BDTR|=(1<<15)|(1<<10);											//enable OC pin MOE
					Timer1->CCER|=(1<<8);													//enable capture compare ch3
		}
		else if (Timer1Config->Ch3_Dir==Input_Ic1_On_Tl1)
		{
			Timer1->CCMR2|=((Timer1Config->Ch3_Input_Filter)<<4);                   //selecting the input fiter
			Timer1->CCMR2|=((Timer1Config->Ch3_Input_PSC)<<2);						//selecting the input prescaler
			Timer1->CCER|=((Timer1Config->Ch3_Input_Edge)<<9);						//rising or falling
			Timer1->CCER |= (1<<8);													//enable capture compare ch1
		}

	}*/
	/********************/
/***********CH4***********/
/*	if(Timer1Config->Ch4==CH_Used)											//this configuration is for channel 4
		{
		Timer1->CCMR2|=((Timer1Config->Ch4_Dir)<<8);							//direction of channel4
		if(Timer1Config->Ch1_Dir==Output)
		{

			Timer1->CCMR2|=((Timer1Config->Ch4_OutputCompare_Preload)<<11);		//enable or disable preload
			Timer1->CCMR2|=((Timer1Config->Ch4_Output_Compare_mode)<<12);			//chanel output mode
			Timer1->CCER|=((Timer1Config->Ch4_Polarity)<<13);						//polarity selection ch4
			Timer1->CCR4=((TIMER1_Ch4_DutyCycle*Timer1->ARR/100));				//duty cycle of ch4
			Timer1->BDTR|=(1<<15)|(1<<10);
			Timer1->CCER|=(1<<12);												//enable capture compare ch4
		}
		 else if (Timer1Config->Ch4_Dir==Input_Ic1_On_Tl1)
			{
				Timer1->CCMR2|=((Timer1Config->Ch4_Input_Filter)<<12);                   //selecting the input fiter
				Timer1->CCMR2|=((Timer1Config->Ch4_Input_PSC)<<10);						//selecting the input prescaler
				Timer1->CCER|=((Timer1Config->Ch4_Input_Edge)<<13);						//rising or falling
				Timer1->CCER |= (1<<12);													//enable capture compare ch1
			}

		}*/
/*********************************************************************************************/
/*	if(Timer1Config->Ch1_Capture_Compare_Interrupt==TIMER_ENABLE)
	{
		Timer1->DIER|=(1<<1);
	}
	else
	{
		Timer1->DIER &= ~(1<<1);
	}
	if(Timer1Config->Ch2_Capture_Compare_Interrupt==TIMER_ENABLE)
		{
			Timer1->DIER|=(1<<2);
		}
	else
	{
		Timer1->DIER &= ~(1<<2);
	}
	if(Timer1Config->Ch3_Capture_Compare_Interrupt==TIMER_ENABLE)
		{
			Timer1->DIER|=(1<<3);
		}
	else
	{
		Timer1->DIER &= ~(1<<3);
	}
	if(Timer1Config->Ch4_Capture_Compare_Interrupt==TIMER_ENABLE)
		{
			Timer1->DIER|=(1<<4);
		}
	else
	{
		Timer1->DIER &= ~(1<<4);
	}

	Timer1->CR1|=(1<<0);													//enable timer1

}*/
/****************************************** all TIMERs ********************************************************/
/********************************************************************************************************/


void Timers_Init(Timer_Config* Timer1Config)
{
	/*TIMER1 BASIC CONFIG*/
	if(Timer1Config->TIM_Num==TIMER1)
	{
		RCC_PerClock_State(APB2 ,11 ,PClock_enable );   								//enable timer1 clock
		Timer_Num[Timer1Config->TIM_Num]->ARR=0xffff;							//Because timer1 is used for ultrasonic sensor
	}
	else if(Timer1Config->TIM_Num==TIMER2)
	{
		RCC_PerClock_State(APB1 ,0 ,PClock_enable );  							// enable timer2 clock
		Timer_Num[Timer1Config->TIM_Num]->ARR=40;								//because timer2 is for motors
	}
	Timer_Num[Timer1Config->TIM_Num]->PSC=7;							//time base = 1us because frequency internal 8Mhz 											  					 //time base =1ms
	//Timer_Num[Timer1Config->TIM_Num]->ARR=40;

	Timer_Num[Timer1Config->TIM_Num]->CR1|=((Timer1Config->Auto_Reload_Preload)<<7);							// enable or disable auto reload
	Timer_Num[Timer1Config->TIM_Num]->CR1|=((Timer1Config->Center_Aligned_mode)<<5);							//select center aligned mode
	Timer_Num[Timer1Config->TIM_Num]->CR1|=((Timer1Config->Counter_Direction)<<4);							//up counting or down counting
				/***********CH1***********/
	if(Timer1Config->Ch1==CH_Used)														//this configuration is for channel 1
	{
		Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch1_Dir)<<0);								//direction of channel1
		if(Timer1Config->Ch1_Dir==Output)
		{
			Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch1_OutputCompare_Preload)<<3);		    //enable or disable preload
			Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch1_Output_Compare_mode)<<4);			  //chanel output mode
			Timer_Num[Timer1Config->TIM_Num]->CCER |= ((Timer1Config->Ch1_Polarity)<<1);						//polarity selection ch1
			Timer_Num[Timer1Config->TIM_Num]->CCR1 =(Timer_Num[Timer1Config->TIM_Num]->ARR)/1;				  //duty cycle of ch1
			Timer_Num[Timer1Config->TIM_Num]->BDTR|=(1<<15)|(1<<10);											//enable OC pin MOE pin
			Timer_Num[Timer1Config->TIM_Num]->CCER |= (1<<0);													//enable capture compare ch1
		}
		else if (Timer1Config->Ch1_Dir==Input_Ic1_On_Tl1)
		{
			Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch1_Input_Filter)<<4);                   //selecting the input fiter
			Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch1_Input_PSC)<<2);						//selecting the input prescaler
			Timer_Num[Timer1Config->TIM_Num]->CCER|=((Timer1Config->Ch1_Input_Edge)<<1);						//rising or falling
			Timer_Num[Timer1Config->TIM_Num]->CCER |= (1<<0);													//enable capture compare ch1
		}
	}

					/********************/
	/***********CH2***********/
	 if(Timer1Config->Ch2==CH_Used)											//this configuration is for channel 2
	{
		 Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch2_Dir)<<8);							//direction of channel2
		 if(Timer1Config->Ch2_Dir==Output)
		 	 {
			 Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch2_OutputCompare_Preload)<<11);		//enable or disable preload
			 Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch2_Output_Compare_mode)<<12);			//chanel output mode
			 Timer_Num[Timer1Config->TIM_Num]->CCER|=((Timer1Config->Ch2_Polarity)<<5);						//polarity selection ch2
			 Timer_Num[Timer1Config->TIM_Num]->CCR2=(Timer_Num[Timer1Config->TIM_Num]->ARR)/1;				//duty cycle of ch2
			 Timer_Num[Timer1Config->TIM_Num]->BDTR|=(1<<15)|(1<<10);											//enable OC pin MOE
			 Timer_Num[Timer1Config->TIM_Num]->CCER|=(1<<4);											//enable capture compare ch2
		 	 }
		 else if (Timer1Config->Ch2_Dir==Input_Ic1_On_Tl1)
			{
			 Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch2_Input_Filter)<<12);                   //selecting the input fiter
			 Timer_Num[Timer1Config->TIM_Num]->CCMR1|=((Timer1Config->Ch2_Input_PSC)<<10);						//selecting the input prescaler
			 Timer_Num[Timer1Config->TIM_Num]->CCER|=((Timer1Config->Ch2_Input_Edge)<<5);						//rising or falling
			 Timer_Num[Timer1Config->TIM_Num]->CCER |= (1<<4);													//enable capture compare ch1
			}

		}

		/********************/
/***********CH3***********/
	 if(Timer1Config->Ch3==CH_Used)													//this configuration is for channel 3
	{
		 Timer_Num[Timer1Config->TIM_Num]->CCMR2|=(Timer1Config->Ch3_Dir<<0);									//direction of channel3
		if(Timer1Config->Ch3_Dir==Output)
		{
			Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch3_OutputCompare_Preload)<<3);					//enable or disable preload
			Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch3_Output_Compare_mode)<<4);			//chanel output mode
			Timer_Num[Timer1Config->TIM_Num]->CCER|=((Timer1Config->Ch3_Polarity)<<9);						//polarity selection ch3
			Timer_Num[Timer1Config->TIM_Num]->CCR3=(Timer_Num[Timer1Config->TIM_Num]->ARR)/1;					//duty cycle of ch3
			Timer_Num[Timer1Config->TIM_Num]->BDTR|=(1<<15)|(1<<10);											//enable OC pin MOE
			Timer_Num[Timer1Config->TIM_Num]->CCER|=(1<<8);													//enable capture compare ch3
		}
		else if (Timer1Config->Ch3_Dir==Input_Ic1_On_Tl1)
		{
			Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch3_Input_Filter)<<4);                   //selecting the input fiter
			Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch3_Input_PSC)<<2);						//selecting the input prescaler
			Timer_Num[Timer1Config->TIM_Num]->CCER|=((Timer1Config->Ch3_Input_Edge)<<9);						//rising or falling
			Timer_Num[Timer1Config->TIM_Num]->CCER |= (1<<8);													//enable capture compare ch1
		}

	}
	/********************/
/***********CH4***********/
	if(Timer1Config->Ch4==CH_Used)											//this configuration is for channel 4
		{
		Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch4_Dir)<<8);							//direction of channel4
		if(Timer1Config->Ch1_Dir==Output)
		{

			Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch4_OutputCompare_Preload)<<11);		//enable or disable preload
			Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch4_Output_Compare_mode)<<12);			//chanel output mode
			Timer_Num[Timer1Config->TIM_Num]->CCER|=((Timer1Config->Ch4_Polarity)<<13);						//polarity selection ch4
			Timer_Num[Timer1Config->TIM_Num]->CCR4=(Timer_Num[Timer1Config->TIM_Num]->ARR)/1;				//duty cycle of ch4
			Timer_Num[Timer1Config->TIM_Num]->BDTR|=(1<<15)|(1<<10);
			Timer_Num[Timer1Config->TIM_Num]->CCER|=(1<<12);												//enable capture compare ch4
		}
		 else if (Timer1Config->Ch4_Dir==Input_Ic1_On_Tl1)
			{
			 Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch4_Input_Filter)<<12);                   //selecting the input fiter
			 Timer_Num[Timer1Config->TIM_Num]->CCMR2|=((Timer1Config->Ch4_Input_PSC)<<10);						//selecting the input prescaler
			 Timer_Num[Timer1Config->TIM_Num]->CCER|=((Timer1Config->Ch4_Input_Edge)<<13);						//rising or falling
			 Timer_Num[Timer1Config->TIM_Num]->CCER |= (1<<12);													//enable capture compare ch1
			}

		}
/**********************************************************************************************/
	if(Timer1Config->Ch1_Capture_Compare_Interrupt==TIMER_ENABLE)
	{
		Timer_Num[Timer1Config->TIM_Num]->DIER|=(1<<1);
	}
	else
	{
		Timer_Num[Timer1Config->TIM_Num]->DIER &= ~(1<<1);
	}
	if(Timer1Config->Ch2_Capture_Compare_Interrupt==TIMER_ENABLE)
		{
		Timer_Num[Timer1Config->TIM_Num]->DIER|=(1<<2);
		}
	else
	{
		Timer_Num[Timer1Config->TIM_Num]->DIER &= ~(1<<2);
	}
	if(Timer1Config->Ch3_Capture_Compare_Interrupt==TIMER_ENABLE)
		{
		Timer_Num[Timer1Config->TIM_Num]->DIER|=(1<<3);
		}
	else
	{
		Timer_Num[Timer1Config->TIM_Num]->DIER &= ~(1<<3);
	}
	if(Timer1Config->Ch4_Capture_Compare_Interrupt==TIMER_ENABLE)
		{
		Timer_Num[Timer1Config->TIM_Num]->DIER|=(1<<4);
		}
	else
	{
		Timer_Num[Timer1Config->TIM_Num]->DIER &= ~(1<<4);
	}

	Timer_Num[Timer1Config->TIM_Num]->CR1|=(1<<0);													//enable timer1

}


/********************************************************************************************************/
/***********************************************************************************************************/



/********************MOTOR CONTROL***************/
/*RCC_Init();
RCC_PerClock_State(APB2, IOPA_PERIPHERAL, PClock_enable);
DIO_PinMode(GPIOA, 0, OUTPUT_SPEED_10MHZ_PP);
DIO_PinMode(GPIOA, 1, OUTPUT_SPEED_10MHZ_PP);
DIO_PinMode(GPIOA, 8, OUTPUT_SPEED_10MHZ_AFPP);
DIO_PinMode(GPIOA, 9, OUTPUT_SPEED_10MHZ_AFPP);
DIO_PinMode(GPIOA, 15, OUTPUT_SPEED_10MHZ_AFPP);

DIO_PinWrite(GPIOA, 0, GPIO_HIGH);*/
/* Timer_Config T;

 	T.TIM_Num=TIMER2;
 	T.Auto_Reload_Preload=TIMER_ENABLE;
 	T.Counter_Direction=Upcounter;
 	T.Center_Aligned_mode=Edge_Aligned_mode;
 	T.Ch1=CH_Used;
 	T.Ch2=CH_Not_Used;
 	T.Ch3=CH_Not_Used;
 	T.Ch4=CH_Not_Used;
 	T.Ch1_Capture_Compare_Interrupt=TIMER_DISABLE;
 	T.Ch1_Dir=Output;
 	T.Ch1_OutputCompare_Preload=TIMER_ENABLE;
 	T.Ch1_Output_Compare_mode=PWMmode1;
 	T.Ch1_Polarity=Ch_Active_High;

 	Timers_Init(&T);*/

