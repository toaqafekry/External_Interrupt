/*
 * Lcd_Interface.h
 *
 *  Created on: Apr 6, 2024
 *      Author: Toa Fekry
 */

#ifndef HAL_HEADER_LCD_INTERFACE_H_
#define HAL_HEADER_LCD_INTERFACE_H_

#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "Lcd_Config.h"
#include "Lcd_Private.h"

void Lcd_SendCommand(u8 Command);

void Lcd_SendData(u8 Data);

void Lcd_SendInit();

void Lcd_SendString(u8 *String);


#endif /* HAL_HEADER_LCD_INTERFACE_H_ */
