#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*WE can use struct for addresses when they are in series*/
typedef	struct
{
	volatile	u32		IMR	;
	volatile	u32		EMR	;
	volatile	u32		RSTR;
	volatile	u32		FSTR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define EXTI			((EXTI_Type *)0x40010400)

#endif
