/* ==========================================================================================================
This is a fork of Rays OpenSprinkler code that is amended to use alternative hardware:

The class library implements a minimal set of functions as a wrapper to facilitate replacement
of the Opensprinkler ENC28J60 class libraries with the Arduino Wiznet5100 Ethernet interface.

Version:     Opensprinkler 2.1.8

Date:        May 2018

Repository:  https://github.com/plainolddave/OpenSprinkler-Arduino

License:     Creative Commons Attribution-ShareAlike 3.0 license

Refer to the README file for more information

========================================================================================================== */

#ifndef _OPENSPRINKLER_ARDUINO_STATION_h
#define _OPENSPRINKLER_ARDUINO_STATION_h

#include <Arduino.h>
#include "defines.h"

class OpenSprinkler_Arduino_StationClass
{
protected:
    // pin definitions for discrete pinouts
    const static uint8_t pins[];

    // maximum boards (each with 8 stations) - includes the controller itself
    const static uint8_t maxBoards;

 public:
	void begin();
    void apply(byte enabled, byte *stationBytes, byte maxExtensionBoards);
    void set(byte boardID, byte stationByte);
    void print(byte enabled, byte *stationBytes);
};

extern OpenSprinkler_Arduino_StationClass OpenSprinklerStation;

#endif

