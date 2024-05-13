/*
 * GIE.h
 *
 *  Created on: Apr 27, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_GIE_GIE_H_
#define MCAL_GIE_GIE_H_

#include "../../Common/Stdtype.h"

#define GIE_SREG    *((volatile u8 *)0x5F)
#define GIE_I         7

void GIE_Enable();
void GIE_Disable();

#endif /* MCAL_GIE_GIE_H_ */
