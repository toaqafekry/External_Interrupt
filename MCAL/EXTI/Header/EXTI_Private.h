/*
 * EXTI_Private.h
 *
 *  Created on: Apr 26, 2024
 *      Author: Toa Fekry
 */

#ifndef MCAL_EXTI_HEADER_EXTI_PRIVATE_H_
#define MCAL_EXTI_HEADER_EXTI_PRIVATE_H_



/* MCUCR Register*/
#define EXTI_ISC00   0
#define EXTI_ISC01   1
#define EXTI_ISC11   2
#define EXTI_ISC10   3

/* MCUCsR Register*/
#define EXTI_ISC2    6

/* GICR Register*/
#define EXTI_INT0   6
#define EXTI_INT1   7
#define EXTI_INT2   5

/*GIFR Register*/
#define EXTI_INTF0   6
#define EXTI_INTF1   7
#define EXTI_INTF2   5

/*SensControl*/
#define LowLevel      1
#define AnyLogic      2
#define FallingEdge   3
#define RisingEdge    4

#endif /* MCAL_EXTI_HEADER_EXTI_PRIVATE_H_ */
