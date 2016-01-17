UPDATE JANUARY 2016
-------------------
  
OpenSprinkler_Arduino V2.0.0	- superceded / it contains deprecated types that will no longer compile in the Arduino IDE
OpenSprinkler_Arduino V2.0.7	- superceded / it contains deprecated types that will no longer compile in the Arduino IDE
OpenSprinkler_Arduino V2.1.6	- current / based on the unified firmware at https://github.com/OpenSprinkler/OpenSprinkler-Firmware
  
Issues and Limitations
----------------------

I STRONGLY recommend:
  - get rid of any Opensprinkler code you may have in your Arduino 'library' folder
  - update your Arduino libraries to the latest from each link below or use the ones I've uploaded to Github in the Libraries folder
  
Libraries
---------

Get them all here -> https://github.com/Dave1001/OpenSprinkler-Arduino/Libraries

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

