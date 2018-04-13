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

class GroProServer
{
    
public:
    GroProServer(int portNum,  char* returnedMessage);
    ~GroProServer();
    ssize_t run(char* returnedMessage);
    void clear(char* returnedMessage);
    void setPort(int portNum);
    void reactivateServer();
    void closePort();
    
    
private:
    int m_portNum {5002};
    int m_sockfd;
    int m_newsockfd;
    char m_tcpBuffer[256];
    
    void error(const char *msg)
    {
        perror(msg);
        //exit(1);
    }
    
};

#endif /* GroProServer_h */
