/*
 * File name            : display.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Processor            : PIC18
 * Author               : Etiq Technologies
 * Created on           : November 30, 2013, 5:24 PM
 * Description          : Display function definitions source file
 */

#if defined(__XC) || defined(__18CXX)
#include "segment.h"
#include "delay.h"
#endif

void Float_digit(unsigned char *arr, float b)  /* Conversion of floating point data to decimal data */
{
float f;
int d;
d = b;			// w = whole number part
*arr = (d/10);
arr++;
*arr = (d%10);
f = b-d;
d = f*100;		// d = decimal part
arr++;
*arr = (d/10);
arr++;
*arr = (d%10);
}

/* Continuous display function in each Seven Segment Display */

void Display(float val)
  {
    int x = 0;
	unsigned char array[5] = {1,2,3,4};
    Float_digit(array, val);
 while(x<=30)
    {
    NumDisplay(array[3], 1);                                    /* Invoking function to disply a digit in desired segment    */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(array[2], 2);                                    /* Invoking function to disply a digit in desired segment    */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(array[1], 3);                                    /* Invoking function to disply a digit in desired segment    */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    NumDisplay(array[0], 4);                                    /* Invoking function to disply a digit in desired segment    */
    Delay_s_();                                                 /* 4ms Delay                                                 */
    x++;
    }
  }
