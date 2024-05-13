/*
 * Lcd_Program.c

 *
 *  Created on: Apr 6, 2024
 *      Author: Toa Fekry
 */
#include <util/delay.h>

#include "../../../Common/Stdtype.h"
#include "../../../Common/BitMath.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "../Header/Lcd_Interface.h"
#include "../Header/Lcd_Private.h"
#include "../Header/Lcd_Config.h"


void Lcd_SendCommand(u8 Command)
{
	//*Select RS Low*//
	DIO_SetOutputForPin(Lcd_ControlGroup,Lcd_RS,DIO_Low);
//	ClrBit(DIO_PORTD,0);
	//*RW*//
	DIO_SetOutputForPin(Lcd_ControlGroup,Lcd_RW,DIO_Low);
//	ClrBit(DIO_PORTD,1);
	//*E*//
	DIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,DIO_High);
//	SetBit(DIO_PORTD,2);

	//*Commad*//
	DIO_SetOutputForGroup(Lcd_DataGroup,Command);
	//*E//
	DIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,DIO_Low);
//	ClrBit(DIO_PORTD,2);
}
void Lcd_SendData(u8 Data)
{
	//*Select RS Low*//
	DIO_SetOutputForPin(Lcd_ControlGroup,Lcd_RS,DIO_High);
//	SetBit(DIO_PORTD,0);
	//*RW*//
	DIO_SetOutputForPin(Lcd_ControlGroup,Lcd_RW,DIO_Low);
//	ClrBit(DIO_PORTD,1);
	//*E*//
	DIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,DIO_High);
//	SetBit(DIO_PORTD,2);

	//*Command*//
	DIO_SetOutputForGroup(Lcd_DataGroup,Data);
	//*E//
	DIO_SetOutputForPin(Lcd_ControlGroup,Lcd_E,DIO_Low);
//	ClrBit(DIO_PORTD,2);

}

void Lcd_SendInit()
{
	//*set direction Pin*//
	//*RS*//
	DIO_SetDirectionForPin(Lcd_ControlGroup,Lcd_RS,DIO_Output);
//	SetBit(DIO_DDRD,0);
//	SetBit(DIO_DDRD,1);
//	SetBit(DIO_DDRD,2);
	//*RW*//
	DIO_SetDirectionForPin(Lcd_ControlGroup,Lcd_RW,DIO_Output);
	//*E*//
	DIO_SetDirectionForPin(Lcd_ControlGroup,Lcd_E,DIO_Output);
	//*Set Direction for Group*//
	DIO_SetDirectionForGroup(Lcd_DataGroup,0xff);


	//*Delay Time*//
	_delay_ms(40);
	Lcd_SendCommand(0x38);    //*FN Set*//
	_delay_ms(2);
	Lcd_SendCommand(0x0C);    //*Display on/off*//
	_delay_ms(2);
	Lcd_SendCommand(0x01);
	_delay_ms(2);
	Lcd_SendCommand(0x06);
	_delay_ms(2);
}


void Lcd_SendString(u8 *String)

{
	u8 i=0;

	while(String[i]!='\0')
	{
		Lcd_SendData(String[i]);
		i++;

	}


}

