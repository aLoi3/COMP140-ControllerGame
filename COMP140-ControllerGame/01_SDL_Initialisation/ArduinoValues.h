#pragma once

struct ArduinoValues
{
	typedef short int16;
	typedef unsigned short uint16;

	uint16 startMarker;

	int16 accelX;
	int16 accelY;
	int16 accelZ;

	uint16 endMarker;
};