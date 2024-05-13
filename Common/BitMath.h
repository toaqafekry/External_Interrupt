/*
 * Bitmath.h
 *
 *  Created on: Apr 5, 2024
 *      Author: Toa Fekry
 */

#ifndef COMMON_BITMATH_H_
#define COMMON_BITMATH_H_

#define SetBit(Reg,BitNo)   Reg|=(1<<BitNo);

#define ClrBit(Reg,BitNo)   Reg&=~(1<<BitNo);

#define TogBit(Reg,BitNo)   Reg^=(1<<BitNo);

#define GetBit(Reg,BitNo)  ((Reg>>BitNo)&1);

#endif /* COMMON_BITMATH_H_ */
