/*
 * File name            : display.h
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Processor            : PIC18
 * Author               : Etiq Technologies
 * Created on           : November 30, 2013, 5:41 PM
 * Description          : ADC result display function declarations header file
 */

#ifndef DISPLAY_H
#define	DISPLAY_H
/* __________________________   Display function header  __________________________________ */
void Display(float val);
/*
 * Include          :       display.h
 * Description      :       Displays ADC result on character LCD
 * Arguments        :       float
 * Returns          :       None
 */

/* __________________________   Float - ASCII conversion function header __________________ */

void Float_ASCII(unsigned char *str, float b);
/*
 * Include          :       display.h
 * Description      :       Floating point to ASCII value conversion 
 * Arguments        :       Address of a string, float
 * Returns          :       None
 */
void Display_(float val);
#endif	/* DISPLAY_H */

