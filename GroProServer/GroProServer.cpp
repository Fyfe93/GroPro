//
//  Server.cpp
//  testConcepts
//
//  Created by Andrew Fyfe on 04/04/2018.
//  Copyright © 2018 Andrew Fyfe. All rights reserved.
//

#include "GroProServer.h"

GroProServer::GroProServer(int portNum)
{
    m_portNum = portNum;

    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    if (m_portNum < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sockfd < 0)
        error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(m_portNum);
    if (bind(m_sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(m_sockfd,5);
    clilen = sizeof(cli_addr);
    m_newsockfd = accept(m_sockfd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    if (m_newsockfd < 0)
        error("ERROR on accept");
    bzero(m_tcpBuffer,256);
}


GroProServer::~GroProServer()
{
    fflush(stdin);
    fflush(stdout);
    close(m_newsockfd);
    close(m_sockfd);
}


void GroProServer::setPort(int portNum)
{
    m_portNum = portNum;
}


void GroProServer::run()
{
    while(1)
    {
        
        fflush(stdin);
        fflush(stdout);

        long n = read(m_newsockfd,m_tcpBuffer,255);
        if (n <= 0){
            error("ERROR reading from socket");
            break;
        }
//        int value = m_tcpBuffer[0] - 50;
//        printf("Here is the message: %d\n",value);
        printf("Command: %s\n",m_tcpBuffer);
//        switch (value) {
//            case -1:
//                printf("Slider1: %s\n",m_tcpBuffer);
//                break;
//            case 0:
//                printf("Slider2: %s\n",m_tcpBuffer);
//                break;
//            case 1:
//                printf("Slider3: %s\n",m_tcpBuffer);
//                break;
//            case 2:
//                printf("Slider4: %s\n",m_tcpBuffer);
//                break;
//
//            default:
//                printf("Slider1: %s\n",m_tcpBuffer);
//                break;
//        }
        bzero(m_tcpBuffer,256);
        *m_tcpBuffer = NULL;

        //n = write(newsockfd,"I got your message",18);
        //if (n < 0) error("ERROR writing to socket");
    }
    fflush(stdin);
    fflush(stdout);
    close(m_newsockfd);
    close(m_sockfd);
    
}
