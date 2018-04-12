#include "PwmClass.h"

//sudo g++ pwmTest.cpp -o pwmTest -lwiringPi -lpthread to compile.

PwmClass::PwmClass()
{
    wiringPiSetup();
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
        softPwmWrite (m_assignedPinsVec[pinIndex], level);
    }
}

void PwmClass::setLevelIrPins(int level)
{
    for (int pinIndex = 0; pinIndex < m_numberOfPins/2; pinIndex++)
    {
        softPwmWrite (m_assignedPinsVec[pinIndex], level);
    }
}

void PwmClass::setLevelUvPins(int level)
{
    for (int pinIndex = m_numberOfPins/2; pinIndex < m_numberOfPins; pinIndex++)
    {
        softPwmWrite (m_assignedPinsVec[pinIndex], level);
    }
}

