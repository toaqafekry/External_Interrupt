/*
 * main.c
 *
 *  Created on: Apr 5, 2024
 *      Author: Toa Fekry
 */


#include <util/delay.h>
#include "MCAL/DIO/Header/DIO_Interface.h"
#include "HAL/LED/Header/Led_Interface.h"
#include "MCAL/EXTI/Header/EXTI_Interface.h"
#include"MCAL/GIE/GIE.h"





/*Call Back Function*/
void Tog();
void main()
{
	/*LED*/
	Led_Init(DIO_GroupB,Led1);

	/*BuZZER*/
	DIO_SetDirectionForPin(DIO_GroupB,DIO_Pin1,DIO_Output);   //*as outputdirection==1*//

	/*Button Direction &Pull up*/
	DIO_SetDirectionForPin(DIO_GroupD,DIO_Pin2,DIO_Input);
	DIO_SetOutputForPin(DIO_GroupD,DIO_Pin2,DIO_High);

	/*INT0*/

	EXTI_CallBack_INT0(Tog);
	EXTI_Init0(RisingEdge);
	GIE_Enable();
	while(1)
	{
		DIO_SetOutputForPin(DIO_GroupB,DIO_Pin0,DIO_High);
		_delay_ms(1000);
		DIO_SetOutputForPin(DIO_GroupB,DIO_Pin0,DIO_Low);
		_delay_ms(1000);
	}
}

//void __vector_1() __attribute__((signal));
//void __vector_1()
//{
//	static u8 BuzzerState= DIO_High;
//	if(BuzzerState==DIO_High)
//	{
//		DIO_SetOutputForPin(DIO_GroupB,DIO_Pin1,DIO_Low);
//		BuzzerState=DIO_Low;
//	}
//	else if (BuzzerState==DIO_Low)
//	{
//		DIO_SetOutputForPin(DIO_GroupB,DIO_Pin1,DIO_High);
//		BuzzerState=DIO_High;
//	}
//}

void Tog()
{
	static u8 BuzzerState= DIO_High;
	if(BuzzerState==DIO_High)
	{
		DIO_SetOutputForPin(DIO_GroupB,DIO_Pin1,DIO_Low);
		BuzzerState=DIO_Low;
	}
	else if (BuzzerState==DIO_Low)
	{
		DIO_SetOutputForPin(DIO_GroupB,DIO_Pin1,DIO_High);
		BuzzerState=DIO_High;
	}
}



