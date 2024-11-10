#include	"Std_Types.h"
#include	"Bit_Math.h"

#include  	"DIO_private.h"
#include	"RCC_interface.h"
#include	"NVIC_interface.h"
#include "../EXTI/EXTI_interface.h"
#include "../EXTI/EXTI_private.h"


#ifndef	NULL
#define NULL	(void *)0
#endif


/*You can add */
static void	(* EXTI0_CallBack)	(void) = NULL;
static void	(* EXTI1_CallBack)	(void) = NULL;



void	EXTI_Init			(void) /*yOU CAN USE THIS FUNCTION for any other external interrupt*/
{
	RCC_PerClock_State(APB2 ,AFIO_PERIPHERAL ,PClock_enable );				//enable the AFIO Peripheral to congigure which port is to be used
	EXTI_SetExtiPort(EXTI_LINE0,EXTI_PORTB);							//LINE0 PORTB
	NVIC_EnableInterrupt(6);												//EXTI0 IS num 6 in vector table
	EXTI_EnableExti(EXTI_LINE0);										//enable from EXTI peripheral
	EXTI_SetExtiEdge(EXTI_LINE0,EXTI_RISING_EDGE);							//select edges
}
void	EXTI_EnableExti	(u8	Copy_u8ExtiNum)
{	
	SET_BIT( EXTI -> IMR , Copy_u8ExtiNum);
}
void	EXTI_SetExtiEdge	(u8 Copy_u8ExtiNum , u8 Copy_u8Edge)
{
	switch(Copy_u8Edge)
	{
		case	EXTI_RISING_EDGE	:	CLR_BIT( EXTI -> FSTR , Copy_u8ExtiNum);
										SET_BIT( EXTI -> RSTR , Copy_u8ExtiNum);	break;
		
		case	EXTI_FALLING_EDGE	:	CLR_BIT( EXTI -> RSTR , Copy_u8ExtiNum);
										SET_BIT( EXTI -> FSTR , Copy_u8ExtiNum);	break;
										
		case	EXTI_IOC_EDGE		:	SET_BIT( EXTI -> RSTR , Copy_u8ExtiNum);
										SET_BIT( EXTI -> FSTR , Copy_u8ExtiNum);	break;
	}
}
void	EXTI_DisableExti	(u8	Copy_u8ExtiNum)
{
	CLR_BIT( EXTI -> IMR , Copy_u8ExtiNum);
}
void	EXTI_EnableSWI		(u8	Copy_u8ExtiNum)
{
	SET_BIT( EXTI -> SWIER , Copy_u8ExtiNum);
}
void	EXTI0_SetCallBack	(void (*ptr) (void))
{
	if(ptr != NULL)
	{
		EXTI0_CallBack  = 	ptr ;
	}
}
void	EXTI1_SetCallBack	(void (*ptr) (void))
{
	if(ptr != NULL)
	{
		EXTI1_CallBack  = 	ptr ;
	}
}

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();		//ISR0();
}
void	EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();		//ISR1();
}

void 	EXTI_SetExtiPort	(u8 Copy_u8ExtiNum , u8 Port)
{
	if(Copy_u8ExtiNum<4)
	{
		AFIO_EXTICR1|=(Port<<(Copy_u8ExtiNum*4));
	}
	else if (Copy_u8ExtiNum<8)
	{
		Copy_u8ExtiNum-=4;
		AFIO_EXTICR2|=(Port<<(Copy_u8ExtiNum*4));
	}
}






