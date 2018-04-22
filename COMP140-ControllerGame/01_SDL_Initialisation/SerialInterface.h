#pragma once

#include <serial\serial.h>
#include <string>
#include <random>

class SerialInterface
{
public:
	SerialInterface();
	~SerialInterface();

	void send(string msg);
	void getPositions();

	int getPot1() { return pot1; };
	int getPot2() { return pot2; };
	int getRandomNumX()
	{
		randomNumX = rand() % 5001 + (-5000);
		return randomNumX;
	}
	int getRandomNumY()
	{
		randomNumY = rand() % 5001 + (-5000);
		return randomNumY;
	}

	void close();

private:
	serial::Serial* mySerial;
	bool connected = false;

	int pot1 = 0;
	int pot2 = 0;
	int randomNumX = 0;
	int randomNumY = 0;
};

