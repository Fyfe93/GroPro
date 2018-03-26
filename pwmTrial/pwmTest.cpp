#include <stdio.h>    // Used for printf() statements
#include <wiringPi.h> // Include WiringPi library!
#include <softPwm.h>

//sudo g++ pwmTest.cpp -o pwmTest -lwiringPi -lpthread to compile.

// Pin number declarations. We're using the Broadcom chip pin numbers.
const int pwmPin = 1; // PWM LED - Broadcom pin 18, P1 pin 12

const int pwmValue = 100; // Use this to set an LED brightness 0-100

int main(void)
{
    // Setup stuff:
    wiringPiSetup(); // Initialize wiringPi -- using WiringPi pin numbers
    softPwmCreate (pwmPin,0,100) ;
    softPwmWrite (pwmPin, pwmValue) ;

    for (;;) delay (1000) ;

    return 0;
}
