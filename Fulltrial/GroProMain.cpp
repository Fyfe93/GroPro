#include <stdio.h>
#include "GroProThread.h"


int main( int argc, const char* argv[] ) {
	GroProThread groProThread1(0);
	GroProThread groProThread2(10);
    
    groProThread1.startrun();
    groProThread2.startlisten();
    groProThread1.join();
    groProThread2.join();
    
    return 0;
}
