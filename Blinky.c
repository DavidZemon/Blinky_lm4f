/* File:    Blinky.c
 * 
 * Author:  David Zemon
 * Project: Blinky
 */

// Includes
#include "Blinky.h"

void crappyMain (void);

// Main function
int main (void) {
#ifdef test_warnings
	crappyMain();
#else
	unsigned int ulLoop;

	SysCtlClockSet(
			SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

	// Enable the peripheral for GPIO port F
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	// Set LED as digital output
	GPIODirModeSet(GPIO_PORTF_BASE, GREEN_LED, GPIO_DIR_MODE_OUT);

	while (1) {
		// Turn on LED
		GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, GREEN_LED);

		// Delay
		for (ulLoop = 0; ulLoop < 200000; ulLoop++)
			;

		// Turn off LED
		GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0);

		// Delay
		for (ulLoop = 0; ulLoop < 200000; ulLoop++)
			;
	}
#endif

	return 0;
}

void crappyMain () {
	volatile unsigned long ulLoop;

	//
	// Enable the GPIO port that is used for the on-board LED.
	//
	SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

	//
	// Do a dummy read to insert a few cycles after enabling the peripheral.
	//
	ulLoop = SYSCTL_RCGC2_R;

	//
	// Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
	// enable the GPIO pin for digital function.
	//
	GPIO_PORTF_DIR_R = GREEN_LED;
	GPIO_PORTF_DEN_R = GREEN_LED;

	//
	// Loop forever.
	//
	while (1) {
		//
		// Turn on the LED.
		//
		GPIO_PORTF_DATA_R |= GREEN_LED;

		//
		// Delay for a bit.
		//
		for (ulLoop = 0; ulLoop < 200000; ulLoop++) {
		}

		//
		// Turn off the LED.
		//
		GPIO_PORTF_DATA_R &= ~(GREEN_LED);

		//
		// Delay for a bit.
		//
		for (ulLoop = 0; ulLoop < 200000; ulLoop++) {
		}
	}
}
