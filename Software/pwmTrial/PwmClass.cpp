#include "PwmClass.h"

//sudo g++ pwmTest.cpp -o pwmTest -lwiringPi -lpthread to compile.

PwmClass::PwmClass()
{
    wiringPiSetup();
    m_level = 100;
}

PwmClass::~PwmClass()
{}

void PwmClass::setupAllPins()
{
    for (int pinIndex = 0; pinIndex < m_numberOfPins; pinIndex++)
    {
        softPwmCreate (m_assignedPinsVec[pinIndex],0,100);
    }
}

void PwmClass::setLevelAllPins(int level)
{
    for (int pinIndex = 0; pinIndex < m_numberOfPins; pinIndex++)
    {
        softPwmWrite (m_assignedPinsVec[pinIndex], m_level);
    }
}
