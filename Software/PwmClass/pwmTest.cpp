#include <stdio.h>  
#include <assert.h>
#include <iostream>
#include "PwmClass.h"

//sudo g++ pwmTest.cpp PwmClass.cpp -o pwmTest -lwiringPi -lpthread to compile.


//UNIT TEST FOR PWM FUNCTIONALITY.
int main(void)
{
    
    bool test_success;
    int passed = 0;
    int totalTests = 1;
    int pwmLevel = 100;
    PwmClass *pwm;
    
    // Test 1: initialising Pwm setup across GPIO pins
    test_success = true;
    try { pwm = new PwmClass(pwmLevel);
        pwm->setupAllPins();
        pwm->setLevelAllPins(pwmLevel);
    }
    catch(std::exception& e) { test_success = false; }
    assert(test_success);
    passed++;
    delete pwm;
    
    
    std::cout << "Test Successes: " << passed << " out of " << totalTests << " tests were successful\n";
    
    for (;;) delay (1000) ;
    
    return 0;
}

