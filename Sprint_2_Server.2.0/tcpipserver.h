#pragma once

#include <iostream>
#include <Ws2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

#ifndef TCPIPSERVER_H_
#define TCPIPSERVER_H_

class tcpserver {

private:
	WSADATA 	wsData;

	SOCKET 		listening;			
	SOCKET 		clientSocket;

	sockaddr_in hint;
	sockaddr_in client;

	WORD 		ver;

	char 		host[NI_MAXHOST];		//Client's remote name
	char		service[NI_MAXHOST];	//Service (i.e. port) the client is connected on

	int 		wsOK;
	int			clientSize;
	int			bytesReceived;

public:
	char 		 receivedData[4096];
	virtual void initializeSocket();
	virtual void createSocket();
	virtual void bindIpAddress();
	virtual void tellListing();
	virtual void waitForConnection();
	virtual void closeSocketListening();
	virtual void receiveMessage(double *value);
	virtual void closeSocket();
	virtual void cleanupWinsock();

	virtual 	 ~tcpserver() {}
};

#endif /* TCPIPSERVER_H_ */