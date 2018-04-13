#include <stdio.h>    // Used for printf() statements
#include "PwmClass.h"

//sudo g++ pwmTest.cpp -o pwmTest -lwiringPi -lpthread to compile.

int main(void)
{
    int pwmLevel = 100;
    PwmClass pwm;
    pwm.setupAllPins();
    pwm.setLevelAllPins(pwmLevel);
    
    for (;;) delay (1000) ;
    
    return 0;
}

