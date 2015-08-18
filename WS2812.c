/* 
 * File:   WS2812.c
 * Author: Gary Bleads G0HJQ
 *
 * Created July 2014
 */
#include <xc.h>
#include "pic18f25k80.h"
#include "config.h"
#include "WS2812.h"

// Call this to write the data in the tmpData[] array to the LED strip
unsigned int var;
void WS2812Write(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN_WS2812_LATCH = 0;
    __delay_us(50);
 
    
//    mainDerp=(char*)derp2;
    
    //replace 0 with 0 if anything fails to work
    int var=4;
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop:    BSF     LATB,0,c               // set the output high
            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero
             // logic ONE  (long HIGH output, followed by short LOW)

writeOne:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,0,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop                 // if not zero, process the next bit.
            BRA     endByte                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero:  BCF     LATB,0,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop                 // if not zero process the next bit

            // Move on to the next byte if any
endByte:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop                // if non-zero, process the next byte

                                            // finished
#endasm

};


// Write an RGB value to a single LED
void SetRGB(unsigned char ledNumber, unsigned char red, unsigned char green, unsigned char blue)
{
    unsigned char i = 3 * ledNumber;
    ledData[i] = green;
    i++;
    ledData[i] = red;
    i++;
    ledData[i] = blue;
}

// Write an RGB value to all LEDs
void SetAllRGB(unsigned char red, unsigned char green, unsigned char blue)
{
    unsigned char idx = 0;

    for (int i=0; i<NUMBER_OF_LEDS; i++)
    {
        ledData[idx] = green;
        idx++;
        ledData[idx] = red;
        idx++;
        ledData[idx] = blue;
        idx++;
    }
}

// Write a color wheel value (hue) to a single LED.
// colour is between 0 and 255.
// 0 = Red,
// 85 = Green
// 170 = Blue
// back to 255 = red again
void SetColor(unsigned char ledNumber, unsigned char color)
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;

    if (color <= 85)
    {
        red = 3*(85-color);
        green = 3*color;
        blue = 0;
    }
    else if (color <=170)
    {
        red = 0;
        green = 3*(170-color);
        blue = 3*(color-85);
    }
    else
    {
        red = 3*(color-170);
        green = 0;
        blue = 3*(255-color);
    }

    unsigned char i = 3 * ledNumber;
    ledData[i] = green;
    i++;
    ledData[i] = red;
    i++;
    ledData[i] = blue;

}



// Write a color wheel value (hue) to all LEDs.
// colour is between 0 and 255.
// 0 = Red,
// 85 = Green
// 170 = Blue
// back to 255 = red again
void SetAllColor(unsigned char color)
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;

    if (color <= 85)
    {
        red = 3*(85-color);
        green = 3*color;
        blue = 0;
    }
    else if (color <=170)
    {
        red = 0;
        green = 3*(170-color);
        blue = 3*(color-85);
    }
    else
    {
        red = 3*(color-170);
        green = 0;
        blue = 3*(255-color);
    }

    unsigned char idx = 0;

    for (int i=0; i<NUMBER_OF_LEDS; i++)
    {
        ledData[idx] = green;
        idx++;
        ledData[idx] = red;
        idx++;
        ledData[idx] = blue;
        idx++;
    }

}
