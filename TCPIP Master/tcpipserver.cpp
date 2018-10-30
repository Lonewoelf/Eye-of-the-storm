#include "tcpipserver.h"

void tcpserver::initializeSocket() {		//Initialize winsock
	ver = MAKEWORD(2, 2);

	wsOK = WSAStartup(ver, &wsData);

	if (wsOK != 0) {
		std::cerr << "Can't Initialize winsock! Quitting" << std::endl;
	}
}

void tcpserver::createSocket() {			//Create a socket
	listening = socket(AF_INET, SOCK_STREAM, 0);

	if (listening == INVALID_SOCKET) {
		std::cerr << "Cant't create a socket! Quitting" << std::endl;
	}
}

void tcpserver::bindIpAddress() {		//Bind the ip address and port to a socket
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));
}

void tcpserver::tellListing() {			//Tell winsock the socket is for listing
	listen(listening, SOMAXCONN);
}

void tcpserver::waitForConnection() {	//Wait for a connection
	clientSize = sizeof(client);

	clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	ZeroMemory(host, NI_MAXHOST); 		//Same as memset(host, 0, NI_MAXHOST)
	ZeroMemory(service, NI_MAXHOST);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
		std::cout << host << " connected on port " << service << std::endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << " connected on port " <<
			ntohs(client.sin_port) << std::endl;
	}
}

void tcpserver::closeSocketListening() {	//Close listening socket
	closesocket(listening);
}

void tcpserver::receiveMessage(int *id, double *temperature, double *humidity, double *windSpeed) {		//Receive message and copy to receivedData variable
	while (true) {
		ZeroMemory(receivedData, 4096);

		//Wait for client to send data
		bytesReceived = recv(clientSocket, receivedData, 4096, 0);
		if (bytesReceived == SOCKET_ERROR) {
			std::cerr << "Error in recv()! Quitting" << std::endl;
			break;
		}

		if (bytesReceived == 0) {
			std::cout << "Client disconnected" << std::endl;
			break;
		}
		
		if (strcmp(receivedData,"\r\n") != 0 ) {
			//send(clientSocket, receivedData, bytesReceived + 1, 0);
			if (strncmp(receivedData, "T ", 2) == 0) {
				*temperature = std::atof(receivedData+2);
				std::cout << "received: " << receivedData + 2 << " " << bytesReceived << std::endl;
			}else if (strncmp(receivedData, "H ", 2) == 0) {
				*humidity = std::atof(receivedData + 2);
				std::cout << "received: " << receivedData + 2 << " " << bytesReceived << std::endl;
			}
			else if (strncmp(receivedData, "I ", 2) == 0) {
				*id = std::atoi(receivedData + 2);
				std::cout << "received: " << receivedData + 2 << " " << bytesReceived << std::endl;
			}
			else if (strncmp(receivedData, "S ", 2) == 0) {
				*windSpeed = std::atoi(receivedData + 2);
				std::cout << "received: " << receivedData + 2 << " " << bytesReceived << std::endl;
			}
		}
		
		
	}
}

void tcpserver::closeSocket() {			//Close the socket
	closesocket(clientSocket);
}

void tcpserver::cleanupWinsock() {		//Cleanup Winsock
	WSACleanup();
}

