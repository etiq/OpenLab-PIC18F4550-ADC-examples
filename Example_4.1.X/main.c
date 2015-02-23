/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Processor            : PIC18
 * Author               : Etiq Technologies
 * Created on           : January 7, 2014, 05:31 PM
 * Description          : Example 1.1 IO_PORTs_1
 *                      : Example code to configure PIC18 ADC module and display the ADC result on character LCD.
 */


#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
    #include <plib/adc.h>
    #include <plib/xlcd.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
    #include <xlcd.h>
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
#include "xlcd_config.h"
#endif

#define _XTAL_FREQ 20000000 								//The speed of external oscillator
    char str1[] = "VOLTAGE ";
    float value;
    unsigned char config_1= ADC_FOSC_16 & ADC_RIGHT_JUST & ADC_20_TAD;
    unsigned char config_2= ADC_CH3 & ADC_INT_OFF & ADC_REF_VDD_VSS;
    unsigned char portconfig= ADC_1ANA;
void main()
{
    ADCON1 = 0X0F;
    OpenXLCD(EIGHT_BIT & LINES_5X7);
    WriteCmdXLCD(0x0C);
    WriteCmdXLCD(0x01);                                            /* Clear display                                                */
    SetDDRamAddr(0x80);                                            /* Set Display data ram address to 0                            */

   putsXLCD((char*)str1);                                              /* writing a string to external LCD                 */
   OpenADC(config_1, config_2, portconfig);                                /* Open ADC module                                  */
     while(1)
       {
        value = ADC_Value();                                                /*ADC conversion*/
        Display(value);
       }
}


