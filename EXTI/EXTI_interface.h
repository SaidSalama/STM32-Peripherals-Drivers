#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void	EXTI_Init			(void);
void	EXTI_EnableExti	(u8	Copy_u8ExtiNum);
void	EXTI_SetExtiEdge	(u8 Copy_u8ExtiNum , u8 Copy_u8Edge);
void	EXTI_DisableExti	(u8	Copy_u8ExtiNum);
void	EXTI_EnableSWI		(u8	Copy_u8ExtiNum);
void	EXTI_SetCallBack	(void (*ptr) (void));
void 	EXTI_SetExtiPort	(u8 Copy_u8ExtiNum , u8 Port);

#define	EXTI_RISING_EDGE			0
#define	EXTI_FALLING_EDGE			1
#define	EXTI_IOC_EDGE				2

/*Interrupts line you can add any line you want*/
#define	EXTI_LINE0					0
#define	EXTI_LINE1					1
#define	EXTI_LINE2					2

/*PORTS of External Interrupts*/
#define EXTI_PORTA				0
#define EXTI_PORTB				1
#define EXTI_PORTC				2
#define EXTI_PORTD				3
#define EXTI_PORTE				4
#define EXTI_PORTF				5
#define EXTI_PORTG				6




#endif
