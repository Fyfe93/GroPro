#include <stdio.h>   
#include <iostream>
#include <vector>
#include <wiringPi.h> // Include WiringPi library!
#include <softPwm.h>

//sudo g++ pwmTest.cpp -o pwmTest -lwiringPi -lpthread to compile.

/*
 This is a class for the GroPro Pwm functionality. It allows easy utilisation of the Pwm on the RaspberryPi using wiringPi. It sets up the desired pins used in this project to output Pwm.
 */

class PwmClass
{
public:
    PwmClass(int defaultLevel); //Sets default pwmLevel 0 - 100
    ~PwmClass();
    void setupAllPins(); // Establishes Pwm to All desired GPIO pins
    
    //Level is from 0-100
    void setLevelAllPins(int level); // Sets the intensity level across all pwm pins
    void setLevelIrPins(int level); // Sets the intensity of the Infrared LED Pins
    void setLevelUvPins(int level); // Sets the intensity of the Ultraviolet LED Pins
    
    
private:
    std::vector<int> m_assignedPinsVec{3,4,28,29,0,1,24,27}; // Default GPIO pins for Pwm
    int m_level {0}; // Default intensity level
    int m_numberOfPins{8}; // total number of pins used
    
 
};


