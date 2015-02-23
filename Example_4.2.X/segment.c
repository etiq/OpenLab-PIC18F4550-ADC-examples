/*
 * File name            : segment.c
 * Compiler             : XC8 compiler
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Processor            : PIC18
 * Created on           : November 2, 2013, 2:30 PM
 * Description          : Seven segment display function definitions source file
 */
#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif
/*_______________________________Code for displying a digit with Decimal point____________________________________*/

#define OUTPUT0_DOT  LATD = ((0b11000000) & (0b01111111))
#define OUTPUT1_DOT  LATD = ((0b11111001) & (0b01111111))
#define OUTPUT2_DOT  LATD = ((0b10100100) & (0b01111111))
#define OUTPUT3_DOT  LATD = ((0b10110000) & (0b01111111))
#define OUTPUT4_DOT  LATD = ((0b10011001) & (0b01111111))
#define OUTPUT5_DOT  LATD = ((0b10010010) & (0b01111111))
#define OUTPUT6_DOT  LATD = ((0b10000010) & (0b01111111))
#define OUTPUT7_DOT  LATD = ((0b11111000) & (0b01111111))
#define OUTPUT8_DOT  LATD = ((0b10000000) & (0b01111111))
#define OUTPUT9_DOT  LATD = ((0b10010000) & (0b01111111))

/*__________________________________Code for each digit to disply_______________________________________*/

#define OUTPUT0  LATD = 0b11000000
#define OUTPUT1  LATD = 0b11111001
#define OUTPUT2  LATD = 0b10100100
#define OUTPUT3  LATD = 0b10110000
#define OUTPUT4  LATD = 0b10011001
#define OUTPUT5  LATD = 0b10010010
#define OUTPUT6  LATD = 0b10000010
#define OUTPUT7  LATD = 0b11111000
#define OUTPUT8  LATD = 0b10000000
#define OUTPUT9  LATD = 0b10010000
#define DEFAULT  LATD = 0b11111111
/* Segment activation bits */
#define Segment_1 LATBbits.LATB0
#define Segment_2 LATBbits.LATB1
#define Segment_3 LATBbits.LATB2
#define Segment_4 LATBbits.LATB3
/* Segment direction bits*/
#define Segment_1_dir TRISBbits.TRISB0
#define Segment_2_dir TRISBbits.TRISB1
#define Segment_3_dir TRISBbits.TRISB2
#define Segment_4_dir TRISBbits.TRISB3
unsigned char dot = 0;

void Segment_init(unsigned char Segment)
    {
    /*  Direction settings  */
    TRISD = 0x00;
    Segment_1_dir = 0;                                          /* Direction of segment 1 set as output                   */
    Segment_2_dir = 0;                                          /* Direction of segment 2 set as output                   */
    Segment_3_dir = 0;                                          /* Direction of segment 3 set as output                   */
    Segment_4_dir = 0;                                          /* Direction of segment 4 set as output                   */
    /*  7 segment Display module selection   */

    switch(Segment)
    {
         case 1: Segment_1 = 1;                                          /* Segment 1 is activated                                 */
                 Segment_2 = 0;
                 Segment_3 = 0;
                 Segment_4 = 0;
                 break;
         case 2: Segment_1 = 0;                                          /* Segment 1 is activated                                 */
                 Segment_2 = 1;
                 Segment_3 = 0;
                 Segment_4 = 0; 
                 break;
         case 3: Segment_1 = 0;                                          /* Segment 1 is activated                                 */
                 Segment_2 = 0;
                 Segment_3 = 1;
                 Segment_4 = 0; 
                 break;
         case 4: Segment_1 = 0;                                          /* Segment 1 is activated                                 */
                 Segment_2 = 0;
                 Segment_3 = 0;
                 Segment_4 = 1; 
                 break;
        default: Segment_1 = 0;                                          /* Segment 1 is activated                                 */
                 Segment_2 = 0;
                 Segment_3 = 0;
                 Segment_4 = 0; 
                 break;
    }

}

void DisplayValue(char Number)
{
 if(dot==1)
   {
    switch (Number)
    {
 case 0 :
                OUTPUT0_DOT;                                        /* Data out to data port of Seven Segment display         */
                break;
 case 1  :
                OUTPUT1_DOT;
                break;
 case 2  :
                OUTPUT2_DOT;
                break;
 case 3  :
                OUTPUT3_DOT;
                break;
 case 4  :
                OUTPUT4_DOT;
                break;
 case 5  :
                OUTPUT5_DOT;
                break;
 case 6  :
                OUTPUT6_DOT;
                break;
 case 7  :
                OUTPUT7_DOT;
                break;
 case 8  :
                OUTPUT8_DOT;
                break;
 case 9  :
                OUTPUT9_DOT;
                break;
    }

    dot=0;
    }
    else
    {
    switch (Number)
    {
 case 0 :
                OUTPUT0;                                        /* Data out to data port of Seven Segment display         */
                break;
 case 1  :
                OUTPUT1;
                break;
 case 2  :
                OUTPUT2;
                break;
 case 3  :
                OUTPUT3;
                break;
 case 4  :
                OUTPUT4;
                break;
 case 5  :
                OUTPUT5;
                break;
 case 6  :
                OUTPUT6;
                break;
 case 7  :
                OUTPUT7;
                break;
 case 8  :
                OUTPUT8;
                break;
 case 9  :
                OUTPUT9;
                break;
    }
  }
}

/* _______________________________Number displaying function________________________________________________________*/

void NumDisplay(char Number, unsigned char Segment )
{
 Segment_init(Segment);                                         /* Invoking function to segment initialization            */
 if(Segment == 3 )
     dot = 1;                                                   /* Display ON DP (Decimal point)                          */
 else
     dot = 0;                                                   /* Display OFF DP (Decimal point)                         */
 DisplayValue(Number);                                          /* Seven Segment Display function call                    */
 }