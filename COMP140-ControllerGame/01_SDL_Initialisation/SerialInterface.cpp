#include "stdafx.h"
#include "SerialInterface.h"
#include <iostream>

using std::cout;
using std::vector;
using std::exception;
using std::stoi;
using std::string;


SerialInterface::SerialInterface()
{
	vector <serial::PortInfo> devicesFound = serial::list_ports();

	vector <serial::PortInfo>::iterator iter = devicesFound.begin();

	while (iter != devicesFound.end())
	{
		serial::PortInfo device = *iter++;
		string port = device.port.c_str();

		try
		{
			mySerial = new serial::Serial(port, 115200, serial::Timeout::simpleTimeout(250));

			if (mySerial->isOpen())
			{
				cout << "Connection success: " << port << '/n';
				connected = true;

				break;
			}
		}

		catch (exception &e)
		{

		}
	}
}


SerialInterface::~SerialInterface()
{
}

void SerialInterface::send(string msg)
{
	if (connected)
	{
		mySerial->write(msg);
	}
}

void SerialInterface::getPositions()
{
	if (connected)
	{
		mySerial->write("O");
		
		string result = mySerial->readline();

		if (result == "S")
		{

			std::cout << "I have found the right spot! \n";
			std::cout << "Want to try again? A random number has already been selected! \n";
		}
	}
}
void SerialInterface::close()
{
	mySerial->flush();
	mySerial->close();
}