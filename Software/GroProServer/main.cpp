

//#include <iostream>
#include <stdio.h>
#include "GroProServer.h"


int main( int argc, const char* argv[] ) {
    int portNo = 5002;
    GroProServer server(portNo);
    server.run();
    
    return 0;
}
