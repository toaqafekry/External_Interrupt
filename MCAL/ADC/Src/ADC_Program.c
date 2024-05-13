/*
 * ADC_Program.c
 *
 *  Created on: May 10, 2024
 *      Author: Toa Fekry
 */

#include "../../../Common/BitMath.h"
#include "../../../Common/Stdtype.h"
#include"../../ADC/Header/ADC_Interface.h"


void ADC_Init(u8 prescaler)
{
	/*select refrence(0,1)*/
	ClrBit(ADCMUX,Refs1);
	SetBit(ADCMUX,Refs0);
	/*selectADLAR*/
	ClrBit(ADCMUX,ADLAR);
	/*Disable autotrigger*/
	ClrBit(ADCSRA,ADATE);
	/*	prescaler divided to 8*/
	prescaler &=0b00000111;
	ADCSRA &=   0b11111000;
	ADCSRA |= prescaler;
    /*enable aden*/
	SetBit(ADCSRA,ADEN);


}
u16 ADC_GetDigitalValue (u8 Channel)
{

      Channel &=0b00011111;
	  ADCMUX &= 0b11100000;
	  ADCMUX |=Channel;

	/*MUX4=>0 00000

	switch(Channel)
	{
	case 0 :     ClrBit(ADCMUX,MUX0);
	             ClrBit(ADCMUX,MUX1);
	             ClrBit(ADCMUX,MUX2);
	             ClrBit(ADCMUX,MUX3);
	             ClrBit(ADCMUX,MUX4);
	break;
	MUX4=>0 00001
	case 1 :    setBit(ADCMUX,MUX0);
	            ClrBit(ADCMUX,MUX1);
	            ClrBit(ADCMUX,MUX2);
	            ClrBit(ADCMUX,MUX3);
	            ClrBit(ADCMUX,MUX4);
	break;
	MUX4=>0 00010
	case 2 :   ClrBit(ADCMUX,MUX0);
	           setbit(ADCMUX,MUX1);
	           ClrBit(ADCMUX,MUX2);
	           ClrBit(ADCMUX,MUX3);
	           ClrBit(ADCMUX,MUX4);
	break;
	MUX4=>0 00011
	case 3:   SetBit(ADCMUX,MUX0);
	          SetBit(ADCMUX,MUX1);
	          ClrBit(ADCMUX,MUX2);
	          ClrBit(ADCMUX,MUX3);
	          ClrBit(ADCMUX,MUX4);
	break;
	MUX4=>0 00100
	case 4:   ClrBit(ADCMUX,MUX0);
	          ClrBit(ADCMUX,MUX1);
	          SetBit(ADCMUX,MUX2);
	          ClrBit(ADCMUX,MUX3);
	          ClrBit(ADCMUX,MUX4);
	break;
	}*/

	/*single mode*/    //ask//   //law free running hktbha e intializtion bss//
	SetBit(ADCSRA,ADSC);
	/* completing the conversion*/
	/*while(ADCSRA & (1<<ADSC));*/
	u8 flagstate=GetBit(ADCSRA,ADIF);
	while (flagstate==0)
	{
		//waiting
		flagstate=GetBit(ADCSRA,ADIF);   //MMKN DO WHILE FE BET

	}

	/*  read the ADCData*/
	u16 ADC;
 /*CLEAR THE FLAG*/
SetBit(ADCSRA,ADIF);
/*	ADC=GetBit(ADCData,7);
	ADC=GetBit(ADCData,6);
	ADC=GetBit(ADCData,5);
	ADC=GetBit(ADCData,4);
	ADC=GetBit(ADCData,3);
	ADC=GetBit(ADCData,2);
	ADC=GetBit(ADCData,1);
	ADC=GetBit(ADCData,0);*/
	ADC=ADCData;



return ADC;
}
