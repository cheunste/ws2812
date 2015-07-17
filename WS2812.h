/* 
 * File:   WS2812.h
 * Author: Gary
 *
 * Created on 06 July 2014, 16:11
 */

#ifndef WS2812_H
#define	WS2812_H

#ifdef	__cplusplus
extern "C" {
#endif

// output pin definitions
#define PIN_WS2812_LATCH LATBbits.LB0

#define PIN0 LATBbits.LB0
#define PIN1 LATBbits.LB1
#define PIN2 LATBbits.LB2
#define PIN3 LATBbits.LB3
#define PIN4 LATBbits.LB4
#define PIN5 LATBbits.LB5
#define PIN6 LATBbits.LB6
#define PIN7 LATBbits.LB7

#define PIN_WS2812_TRISTATE TRISBbits.TRISB0

// number of leds (60 x 3 for green, blue, red)
#define NUMBER_OF_LEDS 80
#define LED_ARRAY_SIZE 80*3


// variables. These are at a fixed address to make it easier for the assembly
// language to share them
unsigned char tmpData @0x0c00;
unsigned char bitCount @0x0c01;
unsigned char ledCount @0x0c02;
unsigned char ledData[LED_ARRAY_SIZE] @0x0c03;

// Load the entire contents of the ledData array to the LED string
void WS2812Write(void);


// set the RGB value (0-255) of a single led.
void SetRGB(unsigned char, unsigned char, unsigned char, unsigned char);

// set the RGB value (0-255) of all LEDs
void SetAllRGB(unsigned char, unsigned char, unsigned char);

// set the colour of a single led.
// color 0 = red,
//      85 = green
//     170 = blue
//      255 = red again
void SetColor(unsigned char, unsigned char);

void SetAllColor(unsigned char);

#ifdef	__cplusplus
}
#endif

#endif	/* WS2812_H */

