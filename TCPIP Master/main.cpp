#include <stdlib.h>
#include <iostream>
#include <string>

#include "database.h"
#include "tcpipserver.h"

using namespace std;

int main(void)
{
	database db;
	tcpserver server;
	int id;
	double temperature, humidity, windSpeed;
	
	db.connect();

	while (1) {
		server.initializeSocket();

		server.createSocket();

		server.bindIpAddress();

		server.tellListing();

		server.waitForConnection();

		server.closeSocketListening();

		server.receiveMessage(&id, &temperature, &humidity, &windSpeed);

		temperature = (((175.72 * temperature) / 65536) - 46.85);
		humidity = (((125 * humidity) / 65536) - 6);
		windSpeed = windSpeed * 2 * 3.14 / 5;

		std::cout << "temperature: " << temperature << std::endl;
		std::cout << "humidity: " << humidity << std::endl;
		std::cout << "windSpeed: " << windSpeed << std::endl;

		server.closeSocket();

		std::cout << std::endl;
		db.insert(id, temperature, humidity, windSpeed);
	}
	db.disconnect();

	return EXIT_SUCCESS;
}