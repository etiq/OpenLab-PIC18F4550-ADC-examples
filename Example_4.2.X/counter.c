/*
 * File name            : counter.c
 * Compiler             : XC8 compiler
 * IDE                  : Microchip MPLAB X IDE v1.90
 * Author               : Etiq Technologies
 * Description          : Example_9.2 Digital Counter_1
 *                      : Created on November 2, 2013, 2:30 PM
 *                      : Counter function definitions source file
 */

void Seq_count(unsigned char*ptr1, unsigned char*ptr2, unsigned char*ptr3, unsigned char*ptr4)
{
 ++*ptr1;
    if(*ptr1==10)
        {
        ++*ptr2;
        *ptr1 = 0;
            if(*ptr2 == 10)
               {
                 ++*ptr3;
                 *ptr2=0;
                        if(*ptr3 == 10)
                        {
                        ++*ptr4;
                        *ptr3=0;
                               if(*ptr4==10)
                               {
                               *ptr4=0;
                               }

                        }

                }

        }

}