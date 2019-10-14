/**
 * @file DigitalOut.h
 * @brief Class for Arduino and Mbed digital outputs
 * @author Dan Oates (WPI Class of 2020)
 * 
 * This class implements the Mbed DigitalOut class for Arduino to allow for
 * cross-platform libraries.
 * 
 * Dependencies:
 * - Platform: https://github.com/doates625/Platform.git
 * 
 * References:
 * - Mbed DigitalOut: https://os.mbed.com/docs/mbed-os/v5.14/apis/digitalout.html
 */
#pragma once
#include <Platform.h>

#if defined(PLATFORM_ARDUINO)

/**
 * Class Declaration
 */
class DigitalOut
{
public:
	DigitalOut(Platform::pintype_t pin, int value = 0);
	void write(int value);
	int read();
	int is_connected();
	DigitalOut& operator=(int value);
	operator int();
protected:
	Platform::pintype_t pin;
	int value;
};

#endif