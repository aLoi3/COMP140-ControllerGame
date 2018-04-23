#pragma once

#include <serial\serial.h>
#include "Text.h"
#include <string>
#include <random>

class SerialInterface
{
public:
	SerialInterface();
	~SerialInterface();

	void send(std::string msg);
	void getPositions();

	void close();

private:
	serial::Serial* mySerial;
	bool connected = false;

	Text success;
	SDL_Rect textDestination;
};