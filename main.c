#include <xc.h>
#include "config.h"
#include "WS2812.h"
#include "pic18f46k80.h"
#include "assemblers.h"
#include "stdio.h"
#include "stdlib.h"
#include "spectrum.h"
#include "uart.h"
// simple delay routine.
// Pauses for approximately the supplied number of milliseconds

void DelayMs(unsigned int x)
{
    for (unsigned int i = 0; i<x ; i++)
    {
        __delay_ms(1);
    }
}

int customAtoi(char *str)
{
    int res = 0; // Initialize result
 
    // Iterate through all characters of input string and update result
    //for (int i = 0; str[i] != '\0'; ++i)
    for (int i = 0; i<=2; i++)
        res = res*10 + str[i] - '0';
 
    // return result.
    return res;
}

// The main entry point. The program starts executing here.
void main()
{

    //Internal Oscillator frequency select bits
    //111 = HF-INTOSC output frequency is used (16 MHz)
    //110 = HF-INTOSC/2 output frequency is used (8 MHz, default)
    OSCCONbits.IRCF = 0b111;
    OSCTUNEbits.PLLEN=1;

//    // A-D Configuration : Disable and set all pins as digital I/O
    ANCON0 = 0b11111111;
    ANCON1 = 0b00011111;

    //For FFT
    
    //Add this in the while loop and only use if it is in spectrum mode
    ADCON0 = 0b00000011; 	// Start the ADC conversion on AN0
    
    // Vss and Vdd as voltage references
	//ADCON1 = 0b00001110;

	// Configure the ADC acquisition time according to the datasheet
	//ADCON2 = 0b10110110; // Note: output is right justified
    
    //End of FFT
    
    LATA  = 0b00000000; // Set all outputs low
    LATB  = 0b00000000;
    LATC  = 0b00000000;

    TRISA  = 0b00000000; // Enable all pins as outputs
    TRISB  = 0b00000000;
    TRISC  = 0b00000000;
    char receiveArray[9];
    char redArray[3];
    char greenArray[3];
    char blueArray[3];
    
    int  red=0;
    int  green=0;
    int  blue=0;
    char *end;

    //Shouldn't really be used as the chrismas lights uses polling
    UART_Init(9600);

//infinite loop to wait for a UART command
    do{
        spectrum();
//        if(RCIF){
//        //PORTB = UART_Read();
//            
//          int i=0;
//          for(i=0;i<=8;i++){
//                while(!RCIF);
////                receiveArray[i]=RCREG;
//                if(i>=0 && i<=2){
//                    redArray[i]=RCREG;
//                }
//                
//                if(i>=3 && i<=5){
//                    greenArray[i-3]=RCREG;
//                }
//
//                if (i>=6 && i<=8){
//                    blueArray[i-6]=RCREG;
//                }
//          }
//            green=customAtoi(greenArray);
//            blue=customAtoi(blueArray);
//            red=customAtoi(redArray);
//            SetAllRGB(0,0,0);
//            SetAllRGB(red,green,blue);
//            writePinMain(0);
//            DelayMs(100);    
//
//      }
    }while(1);
}