/**
 * @file DigitalOut.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "DigitalOut.h"

#if defined(PLATFORM_ARDUINO)

/**
 * @brief Constructs digital output
 * @param pin Platform-specific pin ID
 * @param value Initial output value (0 or 1)
 */
DigitalOut::DigitalOut(PLATFORM_PIN_TYPE pin, int value)
{
	this->pin = pin;
	pinMode(pin, OUTPUT);
	write(value);
}

/**
 * @brief Writes digital output
 * @param value Value to write (0 or 1)
 */
void DigitalOut::write(int value)
{
	this->value = (bool)value;
	digitalWrite(pin, value);
}

/**
 * @param Reads state of digital output (0 or 1)
 */
int DigitalOut::read()
{
	return value;
}

/**
 * @param Returns true if object is connected to output
 * 
 * Note: For Arduino, this always returns true.
 */
int is_connected()
{
	return true;
}

/**
 * @brief Shorthand operator for writing output
 * @param value Value to write (0 or 1)
 */
DigitalOut& DigitalOut::operator=(int value)
{
	write(value);
}

/**
 * @brief Shorthand for reading output
 * @return Output state (0 or 1)
 */
DigitalOut::operator int()
{
	return read();
}

#endif