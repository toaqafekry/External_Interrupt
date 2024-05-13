/*
 * ADC_Register.h
 *
 *  Created on: May 10, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_ADC_HEADER_ADC_REGISTER_H_
#define MCAL_ADC_HEADER_ADC_REGISTER_H_

#include "../../../Common/Stdtype.h"


#define ADCMUX   *((volatile u8 *)0X27)
#define ADCSRA   *((volatile u8 *)0x26)
#define ADCData  *((volatile u16 *)0x24)
#define SFIOR    *((volatile u16 *)0x50)
/*
#define ADCH   *((volatile u8 *)0x25)
#define ADCL   *((volatile u8 *)0x24)
*/



#endif /* MCAL_ADC_HEADER_ADC_REGISTER_H_ */
