/*
 * KeyPad_Program.c
 *
 *  Created on: Apr 19, 2024
 *      Author: Toa Fekry
 */

#include <util/delay.h>
#include "../../../Common/Stdtype.h"
#include "../../../Common/BitMath.h"

#include "../Header/KeyPad_Private.h"
#include "../Header/KeyPad_Config.h"
#include "../Header/KeyPad_Interface.h"

#include "../../../MCAL/DIO/Header/DIO_Interface.h"




u8 KeyPadValue[Row][Column]=

{
		{'1','2','3','/'},
		{'4','5','6','*'},
		{'7','8','9','-'},
		{'C','0','=','+'}
};


void KeyPad_Init()
{
	DIO_SetDirectionForGroup(KeyPad_Group,0x0f);

	DIO_SetOutputForGroup(KeyPad_Group,0Xff);
}

u8 KeyPad_ReadBtnValue()
{

	u8 BtnState= 0;
	u8 BtnValue = 0;
	u8 C = 0;
	u8 R=0;


	//* R3 R2 R1 R0 C3 C2 C1 C0 *//
	//* 7  6  5   4  3  2  1  0 *//

	for( C=0;C<4;C++)
	{
		//*c S LOW*//
		DIO_SetOutputForPin(KeyPad_Group,C,DIO_Low);

		//*Read R*//
		for(R=0;R<4;R++)
		{
			BtnState =DIO_ReadValurForPin(KeyPad_Group,R+4);
			if(BtnState==Pressed)
			{
				BtnValue=KeyPadValue[R][C];
				_delay_ms(150);
				return BtnValue;
			}
		}
	}
	//*C as High*//
	DIO_SetOutputForPin(KeyPad_Group,C,DIO_High);
}

