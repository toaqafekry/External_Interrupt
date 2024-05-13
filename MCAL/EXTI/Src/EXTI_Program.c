/*
 * EXTI_Program.c
 *
 *  Created on: Apr 26, 2024
 *      Author: Toa Fekry
 */

#include "../../../Common/BitMath.h"
#include "../../../Common/Stdtype.h"

#include "../Header/EXTI_Interface.h"


void EXTI_Init0(u8 SensControl)

{
	/*MCUCR Register*/
	if(SensControl==LowLevel)
	{
		//*from datasheet*//
		//ISC00  0  LowLevel
		//ISC01  0  LowLevel
		ClrBit(EXTI_MCUCR,EXTI_ISC00);
		ClrBit(EXTI_MCUCR,EXTI_ISC01);


	}

	else if (SensControl==AnyLogic)
	{
		//*from datasheet*//
		//ISC00  1  Anylogic
		//ISC01  0  Anylogic
		SetBit(EXTI_MCUCR,EXTI_ISC00);
		ClrBit(EXTI_MCUCR,EXTI_ISC01);
	}

	else if (SensControl==FallingEdge)
	{
		//*from datasheet*//
		//ISC00  0  falling
		//ISC01  1  falling
		ClrBit(EXTI_MCUCR,EXTI_ISC00);
		SetBit(EXTI_MCUCR,EXTI_ISC01);
	}
	else if (SensControl==RisingEdge)
	{
		//*from datasheet*//
		//ISC00  1 Rising
		//ISC01  1  Rising
		SetBit(EXTI_MCUCR,EXTI_ISC00);
		SetBit(EXTI_MCUCR,EXTI_ISC01);
	}
	/*Enable The External Interupt*/
	SetBit(EXTI_GICR,EXTI_INT0);

}
void EXTI_DisableInt0()
{
	/*Disable The External Interupt*/
	ClrBit(EXTI_GICR,EXTI_INT0);
}

void EXTI_Init1(u8 SensControl)
{
	/*MCUCR Register*/
	if(SensControl==LowLevel)
	{
		//*from datasheet*//
		//ISC10  0  LowLevel
		//ISC11  0  LowLevel
		ClrBit(EXTI_MCUCR,EXTI_ISC10);
		ClrBit(EXTI_MCUCR,EXTI_ISC11);
	}
	else if(SensControl==AnyLogic)
	{
		//*from datasheet*//
		//ISC10  1  AnyLogic
		//ISC11  0  AnyLogic
		SetBit(EXTI_MCUCR,EXTI_ISC10);
		ClrBit(EXTI_MCUCR,EXTI_ISC11);
	}
	else if(SensControl==FallingEdge)
	{
		//*from datasheet*//
		//ISC10  0 Falling
		//ISC11  1  Falling
		ClrBit(EXTI_MCUCR,EXTI_ISC10);
		SetBit(EXTI_MCUCR,EXTI_ISC11);
	}
	else if(SensControl==RisingEdge)
	{
		//*from datasheet*//
		//ISC10  1 Falling
		//ISC11  1  Falling
		SetBit(EXTI_MCUCR,EXTI_ISC10);
		SetBit(EXTI_MCUCR,EXTI_ISC11);
	}
	/*Enable The External Interupt*/
	SetBit(EXTI_GICR,EXTI_INT1);

}
void EXTI_DisableInt1()
{
	/*Disable The External Interupt*/
	ClrBit(EXTI_GICR,EXTI_INT1);
}
void EXTI_Init2(u8 SensControl)
{
	 if(SensControl==FallingEdge)
		{
			//*from datasheet*//
			//ISC2  0 Falling

			ClrBit(EXTI_MCUCR,EXTI_ISC2);

		}
		else if(SensControl==RisingEdge)
		{
			//*from datasheet*//
			//ISC10  1 RISING

			SetBit(EXTI_MCUCR,EXTI_ISC2);
			}
	 /*Enable The External Interupt*/
	 	SetBit(EXTI_GICR,EXTI_INT2);
}
void EXTI_DisableInt2()
{
	/*Disable The External Interupt*/
		ClrBit(EXTI_GICR,EXTI_INT2);
}



static void(*GINT0)(void)=Null;
static void(*GINT1)(void)=Null;
static void(*GINT2)(void)=Null;

void EXTI_CallBack_INT0(void (*PF)(void))
{
	if(PF!=Null)
	{
		GINT0=PF;
	}
}
void EXTI_CallBack_INT1(void (*PF)(void))

{
	if(PF!=Null)
	{
		GINT0=PF;
	}
}
void EXTI_CallBack_INT2(void (*PF)(void))
{
	{
		if(PF!=Null)
		{
			GINT0=PF;
		}
	}
}

void __vector_1()
{
	if (GINT0!=Null)
	{
		GINT0();
	}
}
void __vector_2()
{
	if (GINT1!=Null)
	{
		GINT1();
	}
}
void __vector_3()
{
	if (GINT2!=Null)
	{
		GINT2();
	}
}
