UPDATE JANUARY 2016 - UNDER DEVELOPMENT
---------------------------------------
  
OpenSprinkler_Arduino V2.0.0	- superceded / it contains deprecated types that will no longer compile in the Arduino IDE
OpenSprinkler_Arduino V2.0.7	- superceded / it contains deprecated types that will no longer compile in the Arduino IDE
OpenSprinkler_Arduino V2.1.6	- under development / based on the unified firmware at https://github.com/OpenSprinkler/OpenSprinkler-Firmware

Overview
--------

OpenSprinkler-Arduino is a fork of Ray's OpenSprinkler code thats amended to use alternative hardware:

- Arduino Mega 2560 (Arduino MCU that can handle compiled code size of around 60K)
- Your choice of ethernet:
	Wiznet W5100 Ethernet with onboard SD Card or
	Enc28j60 ethernet with external SD card
- Freetronics LCD Keypad Shield
- Discrete IO outputs instead of using a shift register 

PLUS this version adds a couple of additional functions:
- ability to reboot daily to ensure stable operation
- ability to display free memory on the LCD for debugging
- heartbeat function to say 'alls well' - flashes an LED and the ':' on the LCD time at 1Hz
- ability to turns the WDT on or off (refer to your reference documentationas to whether WDT is supported by the bootloader on your arduino)

In general the approach is to make the minimum changes necessary to use standard Arduino libraries, and to get alternative hardware to run, and to debug. Otherwise the code is 'as is' from https://github.com/OpenSprinkler/OpenSprinkler-Firmware

Changes from Rays original code are marked with OPENSPRINKLER_ARDUINO (or variations thereof)

Refer to the start of 'Config.h' for options to substitute different hardware and turn functions on or off.

As always - FULL CREDIT to Ray for all his hard work to build and maintain the Open Sprinkler project!

Current Release
---------------

Version:     Opensprinkler V2.1.6 / DEVELOPMENT

Date:        January 2016

Repository:  https://github.com/Dave1001/OpenSprinkler-Arduino

License:     Creative Commons Attribution-ShareAlike 3.0 license

Hardware
--------
   
You'll need:

- Arduino Mega 2560 (or any Arduino with enough progmem to handle binary sketch size of around 60Kb compiled) from [Arduino Mega]

- Wiznet W5100 Ethernet Shield (i.e. Arduino 'standard') - $7 from [Ebay W5100]

- Freetronics LCD Shield from [Freetronics LCD] - This is a fairly common 16x2 LCD, however the main difference is the buttons are onboard the shield and are all sampled using one analog pin (each button has its own ADC voltage read from pin A0 to indicate which one was pressed). 

- Any DS1307 or DS3231 (preferred) Real Time Clock ($1 from [Ebay DS1307] or [Ebay DS3231] 

- Any 5V relay card that can be driven from Arduino digitial output pins. 

- Power supplies(s), ethernet switch, bits & pieces to hook it all up 

Installation
------------

To install and compile this code you need:
   
   1.  Arduino IDE    http://arduino.cc/
  
   2.  Libraries:

   Get them all here -> https://github.com/Dave1001/OpenSprinkler-Arduino/libraries

   Or download them from:

- "Wire.h"          Standard Arduino Library
- "LiquidCrystal.h" Standard Arduino Library
- "SPI.h"           Standard Arduino Library
- "Ethernet.h"      Standard Arduino Library
- "EthernetUdp.h"   Standard Arduino Library
- "ICMPPing.h"      https://github.com/BlakeFoster/Arduino-Ping
- "Time.h"          http://www.pjrc.com/teensy/td_libs_Time.html 
- "TimeAlarms.h"    http://www.pjrc.com/teensy/td_libs_TimeAlarms.html 
- "DS1307RTC.h"     http://www.pjrc.com/teensy/td_libs_DS1307RTC.html
- "SDFat.h"         https://github.com/greiman/SdFat
- "MemoryFree.h"    http://playground.arduino.cc/Code/AvailableMemory which links to https://dl.dropbox.com/u/56421988/MemoryFree.zip

  NOTE - unless you're careful, you may have some issues with the libraries above co-existing with OpenSprinklerGen library. The easiest way to fix it is to remove OpenSprinkler from your Arduino library folder. 

  Assuming you have the libraries above installed, the code here *should* compile without too many issues (good luck!)

[Freetronics LCD]:http://www.freetronics.com/collections/shields/products/lcd-keypad-shield
[Ebay W5100]:http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR3.TRC0.A0.H0.Xw5100+shield&_nkw=w5100+shield&_sacat=0
[Ebay DS1307]:http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2050601.m570.l1313.TR10.TRC2.A0.H0.Xds1307&_nkw=ds1307&_sacat=0
[Ebay DS3231]:http://www.ebay.com/sch/i.html?_from=R40&_trksid=p2047675.m570.l1313.TR9.TRC2.A0.H0.Xds3231.TRS0&_nkw=ds3231&_sacat=0
[Arduino Mega]:http://arduino.cc/en/Main/arduinoBoardMega2560
  
Issues and Limitations
----------------------

If you're trying to make it work:

- For the ENC28J60 Version:
	- sadly I was unable to make one version of the code that simply switches between Wiznet5100 and ENC28J60 with a #define - there were simply too many compiler errors and weird conflicts between libraries. This is the reason that the two versions for Wiznet5100 and ENC28J60 are in seperate folders with seperate .ino files.
	- I'm using non-standard pinouts for SPI so you'll definately need to amend "Defines.h" to update the chipselect pins for SD card and Ethernet to match your configuration

- Library conflicts:
	- if you're not careful you'll get a whole bunch (kind of like .dll hell from Windows in the old days before .net)
	- I STRONGLY recommend:
		- get rid of any Opensprinkler code you may have in your Arduino 'library' folder
		- update your Arduino libraries to the latest from each link below or for even more certainty just use the ones I've uploaded to Github in the folder for this release 

- Chipselect pins for SPI:
	-  D4 on the Freetronics LCD shield clashes with the chipselect pin for the SD card on some W5100 shields. You may need to jumper it to D2 as described at http://forum.freetronics.com/viewtopic.php?t=770

- Multiple Simultaneous Button Presses:
	- some of the functionality on the 'real' Opensprinkler hardware works when multiple buttons are pressed at the same time
	- the buttons on freetronics shield can only be detected one at a time therefore any 'multi-nuton-press- functions are disabled

If you're a developer:

- Software IDE
	- I'm using Visual Studio 2015 Community Edition plus Visual Micro to build and upload code.
	- this release was tested to compile and upload using Arduino IDE Version 1.6.7 (only) 

- LCD Backlight Dimming
	- no idea how dimming of the LCD backlight on the 'real' opensprinkler works / this code just implements simple on(bright) or off 

- Discrete Outputs:
	- the number of discrete pins is pre-defined as 16 maximum - you'll need to edit OpenSprinklerGen2.cpp and defines.h if you want more - make sure they're in multiples of 8 

- ICMP Library
	- needs an include guard on ICMPPing.h (duh)

- Hostname 
	- at this stage hostname isn't implemented for opensprinkler - you'll need to use IP to access 
	- this seems to be a limitation of the Arduino Ethernet library / I haven't gotten around to fixing it yet using one of the work-around libraries

- Port Number
	- port number is currently hard coded (default is 80) until I figure out how to change it dynamically when initialising the EthernetServer object

