/* ====================================================

Version:	OpenSprinkler_Arduino 2.1.6

Date:		January 2016

Repository: https://github.com/Dave1001/OpenSprinkler-Arduino

License:	Creative Commons Attribution-ShareAlike 3.0 license

About:		OpenSprinkler-Arduino is a fork of Ray's OpenSprinkler code that's amended to use alternative hardware:
				- Arduino Mega 2560 (Arduino MCU that can handle compiled code size of around 60K)
				- Your choice of ethernet:
					- Wiznet W5100 Ethernet with onboard SD Card or
					- Enc28j60 ethernet with external SD card
				- Freetronics LCD Keypad Shield
				- Discrete IO outputs instead of using a shift register

			PLUS this version adds a couple of additional functions:
				- ability to reboot daily to ensure stable operation
				- ability to display free memory on the LCD for debugging
				- heartbeat function to say 'alls well' - flashes an LED and the ':' on the LCD time at 1Hz
				- ability to turns the WDT on or off (refer to your reference documentationas to whether WDT is supported by the bootloader on your arduino)

			In general the approach is to make only the absolute minimum changes necessary to use standard Arduino libraries,
			and to get alternative hardware to run. Otherwise the code is 'as is' from https://github.com/OpenSprinkler/OpenSprinkler-Firmware

			Changes from Rays original code are marked with OPENSPRINKLER_ARDUINO (or variations thereof)

			Refer to the start of 'Config.h' for options to substitute different hardware and turn functions on or off.

			As always - FULL CREDIT to Ray for all his hard work to build and maintain the Open Sprinkler project!
*/

#ifndef _OS_CONFIG_H
#define _OS_CONFIG_H

// =================================================================
// Compiler switches - comment out these defines to substitute different hardware and torun on/off functionality
// You can also search the project for these keywords to find where the code has been modified
#define OPENSPRINKLER_ARDUINO
#define OPENSPRINKLER_ARDUINO_DISCRETE			// use discrete IO instead of a shift register to control sprinkler outputs
#define OPENSPRINKLER_ARDUINO_FREETRONICS_LCD	// use Freetronics LCD with keypad
#define OPENSPRINKLER_ARDUINO_W5100				// use Wiznet5100 Ethernet shield (without this the code defaults to the Ethercard enc28j60 library)
#define OPENSPRINKLER_ARDUINO_AUTOREBOOT		// this is an optional function to reboot daily to ensure stable operation
#define OPENSPRINKLER_ARDUINO_FREEMEM			// this is an optional function to display free memory on the LCD for debugging
#define OPENSPRINKLER_ARDUINO_HEARTBEAT			// this is an optional function to say 'alls well' - flashes an LED, and the ':' on the LCD time at 1Hz
#define OPENSPRINKLER_ARDUINO_WDT				// this flag turns the WDT on or off (refer to your reference documentation 
												// for whether the firmware loaded on your Arduino mega supports a WDT)
// =================================================================

#endif  // _OS_CONFIG_H


