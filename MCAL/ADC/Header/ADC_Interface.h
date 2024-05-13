/*
 * ADC_Interface.h
 *
 *  Created on: May 10, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_ADC_HEADER_ADC_INTERFACE_H_
#define MCAL_ADC_HEADER_ADC_INTERFACE_H_

#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Register.h"

void ADC_Init(u8 prescaler);
u16 ADC_GetDigitalValue (u8 Channel);



#endif /* MCAL_ADC_HEADER_ADC_INTERFACE_H_ */
