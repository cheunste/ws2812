/* 
 * File:   config.h
 * Author: Author: mhibbett. mike.hibbett@gmail.com, mjhdesigns.com
 *
 * Created on 25 February 2014, 14:20
 */

#ifndef CONFIG_H
#define	CONFIG_H
#include "pic18f25k80.h"

#ifdef	__cplusplus
extern "C" {
#endif

// 48MHz clock
#define OSC_48MHZ
#define _XTAL_FREQ 48000000
    
#define TESTPIN_W4			RA1
#define TESTPIN_W5			RA2
#define TESTPIN_W6			RA3
    
#pragma config WDTEN = OFF
#pragma config XINST = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF

#pragma config CP0 = OFF
#pragma config WDTPS = 1
#pragma config PLLCFG = ON
//#pragma config OSCCON
//#pragma config DSWDTEN = OFF
//#pragma config OSC = INTOSCPLL
//#pragma config CFGPLLEN = ON
//#pragma config PLLDIV = 2
//#pragma config PLLSEL = PLL96
    #pragma config PLLCFG =1

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

