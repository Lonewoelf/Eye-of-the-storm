#include <stdlib.h>
#include <iostream>
#include <string>

#include "database.h"
#include "sensorValues.h"
#include "tcpipserver.h"

using namespace std;

int main(void)
{
	database db;
	tcpserver server;
	double temperature, humidity;
	
	db.connect();	//Connect to database

	while (1) {
		server.initializeSocket();

		server.createSocket();

		server.bindIpAddress();

		server.tellListing();

		server.waitForConnection();

		server.closeSocketListening();

		server.receiveMessage(&temperature);

		server.initializeSocket();

		server.createSocket();

		server.bindIpAddress();

		server.tellListing();

		server.waitForConnection();

		server.closeSocketListening();

		server.receiveMessage(&humidity);

		temperature = (((175.72 * temperature) / 65536) - 46.85);	//Calculate temperature from received value
		humidity = (((125 * humidity) / 65536) - 6);	//Calculate humidity from received value

		std::cout << "temperature: " << temperature << std::endl;
		std::cout << "humidity: " << humidity << std::endl;

		server.closeSocket();
		db.insert(temperature, humidity);	//Insert values to database
	}
	db.disconnect();	//Disconnect from database

	return EXIT_SUCCESS;
}