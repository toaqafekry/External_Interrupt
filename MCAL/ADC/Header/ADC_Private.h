/*
 * ADC_Private.h
 *
 *  Created on: May 10, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_ADC_HEADER_ADC_PRIVATE_H_
#define MCAL_ADC_HEADER_ADC_PRIVATE_H_

#include "ADC_Register.h"

/*ADCMUX*/
#define Refs1    7
#define Refs0    6
#define ADLAR    5
#define MUX4     4
#define MUX3     3
#define MUX2     2
#define MUX1     1
#define MUX0     0

/*ADCSRA*/
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/*SFIOR*/
#define  ADTS2  7
#define  ADTS1  6
#define  ADTS0  5

#endif /* MCAL_ADC_HEADER_ADC_PRIVATE_H_ */

