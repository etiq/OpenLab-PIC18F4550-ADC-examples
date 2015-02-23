/*
 * File name            : display.h
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Processor            : PIC18
 * Author               : Etiq Technologies
 * Created on           : November 30, 2013, 5:41 PM
 * Description          : Display function declarations header file
 */

#ifndef DISPLAY_H
#define	DISPLAY_H
/* __________________________   Display function header  _______________________________ */
void Display(float val);
/*
 * Include          :       display.h
 * Description      :       Displays ADC result on character LCD
 * Arguments        :       float
 * Returns          :       None
 */

void Float_digit(unsigned char *arr, float b);

#endif	/* DISPLAY_H */

