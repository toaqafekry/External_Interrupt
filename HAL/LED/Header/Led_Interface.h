/*
 * Led_Interface.h
 *
 *  Created on: Apr 16, 2024
 *      Author: Toa Fekry
 */

#ifndef HAL_LED_HEADER_LED_INTERFACE_H_
#define HAL_LED_HEADER_LED_INTERFACE_H_
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include"Led_Private.h"
void Led_Init(u8 LedGroup,u8 LedNumber);
void Led_On(u8 LedGroup,u8 LedNumber);
void Led_Off(u8 LedGroup,u8 LedNumber);
void Led_Toggle(u8 LedGroup,u8 LedNumber,u8 Time);

#endif /* HAL_LED_HEADER_LED_INTERFACE_H_ */
