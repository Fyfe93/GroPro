//
//  GroProServer.h
//  GroPro Real-time Embedded Programming
//
//  Created by Andrew Fyfe on 04/04/2018.
//  Copyright © 2018 Andrew Fyfe. All rights reserved.
//

#ifndef GroProServer_h
#define GroProServer_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*
 This is a class for the GroPro Server functionality. It allows easy utilisation of networking behaviour and the receiving of event data from the GroPro Controller App over the established connection to the RaspberryPi. The Port is defaulted to 5002 but this can be changed if necessary.
 */

class GroProServer
{
    
public:
    GroProServer(int portNum,  char* returnedMessage); // Constructor, establishes the desired port to open and global data buffer
    ~GroProServer();
    ssize_t run(char* returnedMessage); // Writes the received message to a char* and returns whether the operation was successful
    void clear(char* returnedMessage); // Clears the data buffer so that there is no build up of false messages
    void setPort(int portNum); // Sets the port number
    void reactivateServer(); // Reopens port and establishes new server
    void closePort(); // Closes port and closes connection
    
    
private:
    int m_portNum {5002}; // Default port number
    int m_sockfd;
    int m_newsockfd;
    char m_tcpBuffer[256]; // Data buffer
    
    // Function that prompts error with server connection
    void error(const char *msg)
    {
        perror(msg);
        //exit(1);
    }
    
};

#endif /* GroProServer_h */
