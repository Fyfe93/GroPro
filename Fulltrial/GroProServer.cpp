//
//  GroProServer.cpp
//
//
//  Created by Andrew Fyfe on 04/04/2018.
//  Copyright © 2018 Andrew Fyfe. All rights reserved.
//

#include "GroProServer.h"

GroProServer::GroProServer(int portNum, char* returnedMessage)
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
    
    int enable = 1;
    if (setsockopt(m_sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        error("setsockopt(SO_REUSEADDR) failed");
    
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
    bzero(returnedMessage, 50);
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

void GroProServer::closePort()
{
    fflush(stdin);
    fflush(stdout);
    close(m_newsockfd);
    close(m_sockfd);
}

void GroProServer::clear(char *returnedMessage)
{
    fflush(stdin);
    fflush(stdout);
    bzero(returnedMessage,50);
}

void GroProServer::reactivateServer()
{
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    if (m_portNum < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sockfd < 0)
        error("ERROR opening socket");
    int enable = 1;
    if (setsockopt(m_sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
        error("setsockopt(SO_REUSEADDR) failed");
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
    
}


ssize_t GroProServer::run(char* returnedMessage)
{
    ssize_t n = read(m_newsockfd,returnedMessage,49);
    if (n <= 0)
    {
        error("ERROR reading from socket/n Restarting");
        fflush(stdin);
        fflush(stdout);
        shutdown(m_newsockfd, m_sockfd);
        close(m_newsockfd);
        close(m_sockfd);
        //            n = write(m_newsockfd,"I got your message",18);
        //            if (n < 0) error("ERROR writing to socket");
    }
    
    
    return n;
}
