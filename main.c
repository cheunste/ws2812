#include <xc.h>
#include "config.h"
#include "WS2812.h"
#include "pic18f25k80.h"
#include "assemblers.h"
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

// The main entry point. The program starts executing here.
void main()
{
    OSCTUNEbits.PLLEN=1;
    OSCCONbits.IRCF = 0b111;
    

    UART_Init(9600);
//    // A-D Configuration : Disable and set all pins as digital I/O
//    ANCON0 = 0b11111111;
//    ANCON1 = 0b00011111;
    
    //For FFT
    
    //Add this in the while loop and only use if it is in spectrum mode
    //ADCON0 = 0b00000011; 	// Start the ADC conversion on AN0
    
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
    
    //Clear the LEDs on program startup
    SetAllRGB(0,0,0);
    WS2812Write();
    writePinMain(0);
    
    DelayMs(2000);
   
    char receiveArray[255];
    
    //This is for UART. Due to this, your other do while loop won't run.
    //Wait...you ARE using your A port as a UART right?
    do{
        if(UART_Data_Ready())
        {
            //Read
            PORTC = UART_Read();
            //PORTA = UART_Read();
            UART_Read_Text(receiveArray, 255);
            
            //Set the LED to whatever the chip receives from UART
            //However, you do not know which position in receiveArray gives you the 
            //LED values. This will require research once you get the module by mail.
            //For now, just plan on using pin 0 for this
            //SetAllRGB(receiveArray[X1],receiveArray[X2],receiveArray[X3]);
            //writePinMain(0);
        }
        DelayMs(100);
    }while(1);
  
    do {
               
        // All red
//        SetAllRGB(255,0,0);
//        WS2812Write();
//        DelayMs(2000);

        // All yellow
//        SetAllRGB(128,128,0);
//        WS2812Write();
//        DelayMs(2000);

        // All purple
        SetAllRGB(100,0,100);
        writePinMain(0);
        
        DelayMs(5000);
        //All oragne
        SetAllRGB(255,128,0);
        writePinMain(1);
        DelayMs(5000);
        
        //All red
        SetAllRGB(255,0,0);
        writePinMain(2);
        DelayMs(5000);
        
        //all blue
        SetAllRGB(0,0,255);
        writePinMain(3);
        DelayMs(5000);
        
        //All Aqua
        SetAllRGB(0,200,200);
        writePinMain(4);
        DelayMs(5000);
        
        //writePin0();
//        WS2812Write();
        
        //DelayMs(2000);

        // All blue
//        SetAllRGB(0,0,255);
//        WS2812Write();
//        DelayMs(2000);

        // All white
        //SetAllRGB(85,85,85);
//        SetAllRGB(85,85,100);
//        WS2812Write();
//        DelayMs(2000);
//
//        // All black
//        SetAllRGB(0,0,0);
//        WS2812Write();
//        DelayMs(2000);

//        // cycle through all colours.
//        // note the use of an int to avoid overflow problems in the
//        // for loop when we reach 255.
//        for (unsigned int repeat = 0; repeat < 4; repeat++)
//        {
//            for (unsigned int color = 0; color <= 255; color++)
//            {
//                SetAllColor(color);
//                WS2812Write();
//                DelayMs(20);
//            }
//        }
//
//        // moving rainbow
//        for (unsigned char repeat = 0; repeat < 6; repeat++)
//        {
//            for (unsigned int startColor = 0; startColor <= 255; startColor++)
//            {
//                unsigned char color = startColor;
//                for (unsigned char led = 0; led < 60; led++)
//                {
//                    SetColor(led, color);
//                    color += 4;
//                }
//                WS2812Write();
//                DelayMs(10);
//            }
//        }

    } while (1);
}


