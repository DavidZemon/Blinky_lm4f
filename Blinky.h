/* File:    Blinky.h
 * 
 * Author:  David Zemon
 * Project: Blinky
 */

#ifndef BLINKY_H_
#define BLINKY_H_

#include <inc/lm4f120h5qr.h>

#ifdef DEBUG
void __error__(char *pcFilename, unsigned long ulLine) {}
#endif

// Comment out this line to test wchar_t warnings
//#define test_warnings

#ifndef test_warnings
#include <inc/hw_memmap.h>
#include <inc/hw_types.h>
#include <inc/hw_ints.h>

#include <driverlib/sysctl.h>
#include <driverlib/pin_map.h>
#include <driverlib/gpio.h>

#define GREEN_LED GPIO_PIN_1
#else
#define GREEN_LED 0x01
#endif

#endif /* BLINKY_H_ */
