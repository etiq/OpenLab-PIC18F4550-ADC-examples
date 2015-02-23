/*
 * File name            : segment.h
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Processor            : PIC18
 * Created on           : November 2, 2013, 2:30 PM
 * Description          : Seven segment display functions declaration header file
 */

#ifndef SEGMENT_H
#define	SEGMENT_H

/* ___________________________Number display functions header______________________________ */

void NumDisplay(char Number, unsigned char Segment );


/*
 * Include          :       segment.h
 * Description      :       Generates code
 * Arguments        :       Decimal numbers
 * Returns          :       None
 */

/* ______________________Segment initialization functions header______________________________ */

void Segment_init(unsigned char Segment);

/*
 * Include          :       segment.c
 * Description      :       Activates a specific seven segment
 * Arguments        :       Decimal number
 * Returns          :       None
 */

void DisplayValue(char Number);

#endif	/* SEGMENT_H */