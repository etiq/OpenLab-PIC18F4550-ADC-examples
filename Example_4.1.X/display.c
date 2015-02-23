/*
 * File name            : display.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Processor            : PIC18
 * Author               : Etiq Technologies
 * Created on           : November 30, 2013, 5:24 PM
 * Description          : ADC result display function definitions source file
 */

#if defined(__XC) || defined(__18CXX)
#include <stdio.h>
#endif

#if defined(__18CXX)
#include <xlcd.h>

void Float_ASCII(unsigned char *str, float b)    /* Floating point to ASCII value conversion    */
{
float f;
int d,w;
w = b;                                              /* w = whole number part of w               */
f = b-w;
d = f*100;                                          /* d = decimal part of w                    */
*str =  w + '0';                                    /* Hexa decimal to ASCII conversion         */
str++;
*str = '.';
str++;
*str = (d/10)+'0';                                  /* Digit of 10's place                      */
str++;
*str = (d%10)+'0';                                  /* Digit of 1's place                       */
}

void Display(float val)
  {
     unsigned char str[6] = "\0";
     Float_ASCII(str, val);
     str[4] = 'V'; 
	 WriteCmdXLCD(0x88);                              /* XLCD command to move cursor to 8th character position   */
     putsXLCD(str);                                   /* XLCD string write function call                         */
  }

#elif defined(__XC)

#include <plib\xlcd.h>

 void Display(float val)
  {
     unsigned char voltage[6] = "\0";
     sprintf( voltage, "%1.2fV", val);
     WriteCmdXLCD(0x88);
     putsXLCD(voltage);
  }
#endif


