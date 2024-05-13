/*
 * DIO_Program.c
 *
 *  Created on: Apr 5, 2024
 *      Author: Toa Fekry
 */


#include "../../../Common/Stdtype.h"
#include "../../../Common/BitMath.h"
#include "../Header/DIO_Register.h"
#include "../Header/DIO_Private.h"
#include "../Header/DIO_Interface.h"

//*pin*//

//*for Direction*//
void DIO_SetDirectionForPin(u8 GroupName,u8 PinNumber,u8 DirectionState)

{
	if(GroupName>=DIO_GroupA &&GroupName<=DIO_GroupD)
	{

		if( PinNumber>=DIO_Pin0 &&PinNumber<=DIO_Pin7)
		{

			if(DirectionState==DIO_Input)

			{
				switch(GroupName)
				{
				case DIO_GroupA : ClrBit(DIO_DDRA,PinNumber); break;
				case DIO_GroupB : ClrBit(DIO_DDRB,PinNumber); break;
				case DIO_GroupC : ClrBit(DIO_DDRC,PinNumber); break;
				case DIO_GroupD : ClrBit(DIO_DDRD,PinNumber); break;

				}
			}
			else if (DirectionState==DIO_Output)
			{
				switch(GroupName)
				{
				case DIO_GroupA : SetBit(DIO_DDRA,PinNumber); break;
				case DIO_GroupB :SetBit(DIO_DDRB,PinNumber); break;
				case DIO_GroupC : SetBit(DIO_DDRC,PinNumber); break;
				case DIO_GroupD : SetBit(DIO_DDRD,PinNumber); break;

				}
			}
		}


	}


}

//*Output*//
void DIO_SetOutputForPin(u8 GroupName,u8 PinNumber,u8 OutputState)
{
	if(GroupName>=DIO_GroupA &&GroupName<=DIO_GroupD)
	{

		if( PinNumber>=DIO_Pin0 &&PinNumber<=DIO_Pin7)
		{

			if(OutputState==DIO_Low)

			{
				switch(GroupName)
				{
				case DIO_GroupA : ClrBit(DIO_PORTA,PinNumber); break;
				case DIO_GroupB : ClrBit(DIO_PORTB,PinNumber); break;
				case DIO_GroupC : ClrBit(DIO_PORTC,PinNumber); break;
				case DIO_GroupD : ClrBit(DIO_PORTD,PinNumber); break;

				}


			}
			else if (OutputState==DIO_High)
			{
				switch(GroupName)
				{
				case DIO_GroupA : SetBit(DIO_PORTA,PinNumber); break;
				case DIO_GroupB :SetBit(DIO_PORTB,PinNumber); break;
				case DIO_GroupC : SetBit(DIO_PORTC,PinNumber); break;
				case DIO_GroupD : SetBit(DIO_PORTD,PinNumber); break;

				}
			}
		}


	}


}

//*Get the Value*//
u8 DIO_ReadValurForPin(u8 GroupName,u8 PinNumber)
{


	u8 result=0;
	if(GroupName>=DIO_GroupA && GroupName <=DIO_GroupD)
	{
		if(PinNumber>=DIO_Pin0 && PinNumber <=DIO_Pin7)
		{
			switch(GroupName)
			{
			case DIO_GroupA : result= GetBit(DIO_PINA,PinNumber); break;
			case DIO_GroupB : result=  GetBit(DIO_PINB,PinNumber); break;
			case DIO_GroupC : result= GetBit(DIO_PINC,PinNumber); break;
			case DIO_GroupD : result= GetBit(DIO_PIND,PinNumber); break;
			}
		}
	}
	return result;
}


//* Group*//

void DIO_SetDirectionForGroup(u8 GroupName,u8 DirectionState)

{
	if(GroupName>=DIO_GroupA &&GroupName<=DIO_GroupD)
	{
		if(DirectionState>=0x00 && DirectionState<=0xff)  //*INPUT= 0*//
		{
			switch(GroupName)
			{
			case DIO_GroupA : DIO_DDRA=DirectionState;   break;
			case DIO_GroupB : DIO_DDRB=DirectionState;   break;
			case DIO_GroupC : DIO_DDRC=DirectionState;   break;
			case DIO_GroupD : DIO_DDRD=DirectionState;   break;
			}

		}


	}
}
void DIO_SetOutputForGroup(u8 GroupName,u8 OutputState)
{
	if(GroupName>=DIO_GroupA &&GroupName<=DIO_GroupD)
	{
		if(OutputState>=0x00 &&OutputState<=0xff)
		{
			switch(GroupName)
			{
			case DIO_GroupA : DIO_PORTA=OutputState;   break;
			case DIO_GroupB : DIO_PORTB=OutputState;   break;
			case DIO_GroupC : DIO_PORTC=OutputState;   break;
			case DIO_GroupD : DIO_PORTD=OutputState;   break;
			}

		}
	}
}

u8 DIO_SetInputForGroup(u8 GroupName)
{
	u8 result=0;

	if(GroupName>=DIO_GroupA && GroupName <=DIO_GroupD)
	{
		switch(GroupName)
		{
		case DIO_GroupA :  result= DIO_PINA;   break;
		case DIO_GroupB :  result= DIO_PINB;   break;
		case DIO_GroupC : result= DIO_PINC;   break;
		case DIO_GroupD :result=  DIO_PIND;   break;
		}
	}
	return result ;
}

