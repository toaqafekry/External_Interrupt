/*
 * Stepper.c
 *
 *  Created on: Apr 20, 2024
 *      Author: Toa Fekry
 */


#include <util/delay.h>
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/Stepper_Interface.h"

void Control_Steper(int Angle)
{
	DIO_SetDirectionForGroup(DIO_GroupA,0xff);
	u16 NoofSteps;
	u16 NoofIritation;
	NoofSteps=Angle/0.17514;
//	NoofSteps=512;
	NoofIritation=NoofSteps/4;
//	NoofIritation=128;
	for(u8 i =0;i<NoofIritation;i++)
	{

		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin0,DIO_High);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin1,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin2,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin3,DIO_Low);
		_delay_ms(10);

		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin0,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin1,DIO_High);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin2,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin3,DIO_Low);
		_delay_ms(10);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin0,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin1,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin2,DIO_High);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin3,DIO_Low);
		_delay_ms(10);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin0,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin1,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin2,DIO_Low);
		DIO_SetOutputForPin(DIO_GroupA,DIO_Pin3,DIO_High);
		_delay_ms(10);
	}

}
