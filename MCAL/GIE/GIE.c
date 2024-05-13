/*
 * GIE.C
 *
 *  Created on: Apr 27, 2024
 *      Author: Toa Fekry
 */


#include "../../Common/BitMath.h"
#include "GIE.h"

void GIE_Enable()
{
	SetBit(GIE_SREG,7);
}
void GIE_Disable()
{
	ClrBit(GIE_SREG,7)
}
