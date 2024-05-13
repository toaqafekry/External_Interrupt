/*
 * Keypad_Config.h
 *
 *  Created on: Apr 19, 2024
 *      Author: Toa Fekry
 */

#ifndef HAL_KEYPAD_HEADER_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_HEADER_KEYPAD_CONFIG_H_


#define Row  4
#define Column 4


//* R3 R2 R1 R0 C3 C2 C1 C0 *//
//* 7  6  5   4  3  2  1  0 *//
#define KeyPad_Group        DIO_GroupA

#define KeypadTypeConnection    0x0f



#endif /* HAL_KEYPAD_HEADER_KEYPAD_CONFIG_H_ */
