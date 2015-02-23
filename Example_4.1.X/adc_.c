/*
 * File name            : adc_.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Processor            : PIC18
 * Author               : Etiq Technologies
 * Created on           : December 2, 2013, 10:48 AM
 * Description          : ADC conversion function definition source file
 */

#if defined(__XC)
    #include <plib\adc.h>

#elif defined(__18CXX)
   #include <adc.h>   /* C18 ADC Include File */
#endif

float ADC_Value()
{
    float value = 0.0;                                          /* declaration and initialization of floating point variable */
    ConvertADC();                                               /* Conversion of analog Quantity to digital Quantity */
    while(BusyADC());                                           /* Waiting until ADC module goes to idle state */
    value = ReadADC();                                          /* Reading ADC value from the register */
    return((value * 5)/1024);                                   /* Voltage = Value * (+Vref-(-Vref))/Total number of steps  */                                                                /*For 10 bit resolution, Total number of steps= 2^10 = 1024*/
}
