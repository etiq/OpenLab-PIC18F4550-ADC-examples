/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Processor            : PIC18
 * Author               : Etiq Technologies
 * Created on           : January 7, 2014, 05:31 PM
 * Description          : Example 4.2 Analog to digital Conversion_2
 *                      : Example code to configure PIC18 ADC module and display the ADC result on seven segment display.
 */

/*
 *  Example 4.2 demonstrates
 *
 *  1. Configuring ADC module
 *  2. Writing ADC value to Seven Segment Display
 *
 *  PORT Connections
 *  ----------------
 *  1. Control PORT     - Connector J4 of Seven Segment Display board to PORTB on base board
 *  2. Data PORT        - Connector J3 of Seven Segment Display board to PORTD on base board
 *  3. Analog CHANNEL   - AN0 (pin RA0 of PORTA)
 * 
 * Operation
 * ---------
 * Controller starts conversion of Analog quantity to 10bit digital data, and displays the value on Seven Segment Display.
 */

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
    #include <plib/adc.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
    #include <adc.h>
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#if defined(__XC) || defined(__18CXX)
#include "config.h"
#include "adc_.h"
#include "delay.h"
#include "display.h"
#include "segment.h"
#endif

#define _XTAL_FREQ 20000000 			//The speed of external oscillator
    float value;
    unsigned char config_1 = ADC_FOSC_32 & ADC_RIGHT_JUST & ADC_20_TAD;
    unsigned char config_2 = ADC_CH0 & ADC_INT_OFF & ADC_REF_VDD_VSS;
    unsigned char portconfig = ADC_1ANA;

void main()
{
  OpenADC(config_1, config_2, portconfig);          /* Open ADC module                                  */                                                
  while(1)
    {
    value = ADC_Value();                             /* ADC conversion                                    */
    Display(value);                                  /* Display ADC value                                 */
    }
}