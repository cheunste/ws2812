#include <xc.h>
#include "pic18f25k80.h"
#include "config.h"
#include "WS2812.h"
#include "assemblers.h"


void writePinMain(int pinChoice){

    switch(pinChoice){
        case 1: writePin1(); break;
        case 2: writePin2(); break;
        case 3: writePin3();break;
        case 4: writePin4();break;
        case 5: writePin5();break;
        case 6: writePin6();break;
        case 7: writePin7();break;
        default:writePin0();break;
    } 
}

void writePin0(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN0 = 0;
    __delay_us(50);
    //replace 0 with 0 if anything fails to work
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop0:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop0:    BSF     LATB,0,c               // set the output high

            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero0

             // logic ONE  (long HIGH output, followed by short LOW)
writeOne0:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,0,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop0                 // if not zero, process the next bit.
            BRA     endByte0                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero0:  BCF     LATB,0,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop0                 // if not zero process the next bit

            // Move on to the next byte if any
endByte0:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop0                // if non-zero, process the next byte

                                            // finished
#endasm

}

void writePin1(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN_WS2812_LATCH = 0;
    __delay_us(50);
    //replace 0 with 0 if anything fails to work
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop1:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop1:    BSF     LATB,1,c               // set the output high

            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero1

             // logic ONE  (long HIGH output, followed by short LOW)
writeOne1:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,1,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop1                 // if not zero, process the next bit.
            BRA     endByte1                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero1:  BCF     LATB,1,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop1                 // if not zero process the next bit

            // Move on to the next byte if any
endByte1:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop1                // if non-zero, process the next byte

                                            // finished
#endasm

}

void writePin2(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN_WS2812_LATCH = 0;
    __delay_us(50);
    //replace 0 with 0 if anything fails to work
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop2:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop2:    BSF     LATB,2,c               // set the output high

            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero2

             // logic ONE  (long HIGH output, followed by short LOW)
writeOne2:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,2,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop2                 // if not zero, process the next bit.
            BRA     endByte2                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero2:  BCF     LATB,2,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop2                 // if not zero process the next bit

            // Move on to the next byte if any
endByte2:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop2                // if non-zero, process the next byte

                                            // finished
#endasm

}

void writePin3(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN_WS2812_LATCH = 0;
    __delay_us(50);
    //replace 0 with 0 if anything fails to work
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop3:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop3:    BSF     LATB,3,c               // set the output high

            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero3

             // logic ONE  (long HIGH output, followed by short LOW)
writeOne3:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,3,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop3                 // if not zero, process the next bit.
            BRA     endByte3                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero3:  BCF     LATB,3,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop3                 // if not zero process the next bit

            // Move on to the next byte if any
endByte3:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop3                // if non-zero, process the next byte

                                            // finished
#endasm

}

void writePin4(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN_WS2812_LATCH = 0;
    __delay_us(50);
    //replace 0 with 0 if anything fails to work
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop4:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop4:    BSF     LATB,4,c               // set the output high

            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero4

             // logic ONE  (long HIGH output, followed by short LOW)
writeOne4:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,4,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop4                 // if not zero, process the next bit.
            BRA     endByte4                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero4:  BCF     LATB,4,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop4                 // if not zero process the next bit

            // Move on to the next byte if any
endByte4:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop4                // if non-zero, process the next byte

                                            // finished
#endasm

}

void writePin5(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN_WS2812_LATCH = 0;
    __delay_us(50);
    //replace 0 with 0 if anything fails to work
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop5:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop5:    BSF     LATB,5,c               // set the output high

            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero5

             // logic ONE  (long HIGH output, followed by short LOW)
writeOne5:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,5,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop5                 // if not zero, process the next bit.
            BRA     endByte5                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero5:  BCF     LATB,5,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop5                 // if not zero process the next bit

            // Move on to the next byte if any
endByte5:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop5                // if non-zero, process the next byte

                                            // finished
#endasm

}

void writePin6(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN_WS2812_LATCH = 0;
    __delay_us(50);
    //replace 0 with 0 if anything fails to work
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop6:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop6:    BSF     LATB,6,c               // set the output high

            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero6

             // logic ONE  (long HIGH output, followed by short LOW)
writeOne6:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,6,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop6                 // if not zero, process the next bit.
            BRA     endByte6                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero6:  BCF     LATB,6,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop6                 // if not zero process the next bit

            // Move on to the next byte if any
endByte6:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop6                // if non-zero, process the next byte

                                            // finished
#endasm

}

void writePin7(void)
{
    // The data pin must be low for at least 50uS to reset the LED drivers
    PIN_WS2812_LATCH = 0;
    __delay_us(50);
    //replace 0 with 0 if anything fails to work
#asm
            MOVLB   HIGH(_tmpData)          // select memory bank 12, so we can access the relevant variables

            MOVLW   LED_ARRAY_SIZE          // ledCount = total number of leds
            MOVWF   BANKMASK(_ledCount),b

            LFSR    0, _ledData             // initialise the ledData pointer to the start of the array (FSR0 = address of _ledData)

byteLoop7:   MOVF    POSTINC0,W,c            // get the next byte of ledData and increment the FSR0 pointer
            MOVWF   BANKMASK(_tmpData),b    // save it in tmpData

            MOVLW   0x08;                   // bitCount = 8;
            MOVWF   BANKMASK(_bitCount),b

bitLoop7:    BSF     LATB,7,c               // set the output high

            BTFSS   BANKMASK(_tmpData), 7,b // test the m.s. bit of tmpData.
            BRA     writeZero7

             // logic ONE  (long HIGH output, followed by short LOW)
writeOne7:   RLNCF   BANKMASK(_tmpData),b   // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            BCF     LATB,7,c                // set the output pin low
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop7                 // if not zero, process the next bit.
            BRA     endByte7                 // zero - goto the next byte

             // logic ZERO (short HIGH output, followed by long LOW)
writeZero7:  BCF     LATB,7,c                // set output low
            RLNCF   BANKMASK(_tmpData),b    // shift tmpData left one place
            NOP
            NOP
            NOP
            NOP
            NOP
            NOP
            DECFSZ  BANKMASK(_bitCount),b   // decrement the bit counter
            BRA     bitLoop7                 // if not zero process the next bit

            // Move on to the next byte if any
endByte7:    DECFSZ  BANKMASK(_ledCount),b   // decrement the byte counter
            BRA     byteLoop7                // if non-zero, process the next byte

                                            // finished
#endasm

}
