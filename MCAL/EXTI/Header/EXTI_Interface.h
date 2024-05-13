/*
 * EXTI_Interface.h
 *
 *  Created on: Apr 26, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

#include "../../../Common/Stdtype.h"
#include "EXTI_Register.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

/*enable Interupt*/
void EXTI_Init0(u8 SensControl);
void EXTI_Init1(u8 SensControl);
void EXTI_Init2(u8 SensControl);

/*disable*/

void EXTI_DisableInt0();
void EXTI_DisableInt1();
void EXTI_DisableInt2();

/*ISR Code*/
void __vector_1() __attribute__((signal));
void __vector_2() __attribute__((signal));
void __vector_3() __attribute__((signal));

void EXTI_CallBack_INT0(void (*PF)(void));
void EXTI_CallBack_INT1(void (*PF)(void));
void EXTI_CallBack_INT2(void (*PF)(void));



#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
