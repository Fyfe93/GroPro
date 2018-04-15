

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "GroProServer.h"

// Unit Test for RaspberryPi Server functionality
int main( int argc, const char* argv[] ) {
    
    bool test_success;
    int passed = 0;
    int totalTests = 2;
    int portNo = 5002;
    
    char* returnedMessage;
    returnedMessage = new char[50];
    
    GroProServer* server(portNo);
    
    //Test 1: Contructor and initial port opening
    test_success = true;
    try { server = new GroProServer(portNo);}
    catch(std::exception& e) { test_success = false; }
    assert(test_success);
    passed++;
    delete server;
    
    //Test 2: Establish port listener
    test_success = true;
    try { server = new GroProServer(portNo);
        ssize_t error = server->run(returnedMessage);;
    }
    catch(std::exception& e) { test_success = false; }
    assert(test_success);
    passed++;
    delete server;
    delete[] returnedMessag;


    std::cout << "Test Successes: " << passed << " out of " << totalTests << " tests were successful\n";
    
    
    return 0;
}




