/*
 * DIO_Interface.h
 *
 *  Created on: Apr 5, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_
#include "../../../Common/Stdtype.h"
#include "DIO_Register.h"
#include "DIO_Private.h"



//*Set The Direction*//
void DIO_SetDirectionForPin(u8 GroupName,u8 PinNumber,u8 DirectionState);
void DIO_SetDirectionForGroup(u8 GroupName,u8 DirectionState);

//*Output*//
void DIO_SetOutputForPin(u8 GroupName,u8 PinNumber,u8 OutputState);
void DIO_SetOutputForGroup(u8 GroupName,u8 OutputState);

//*Input*//
u8 DIO_ReadValurForPin(u8 GroupName,u8 PinNumber);         //*u8 because this fn will return*//
u8 DIO_SetInputForGroup(u8 GroupName);

//*steper*//


#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
