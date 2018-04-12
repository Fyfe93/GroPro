#include <iostream>
#include "Max7221DriverClass.h"
#include "pid.h"
#include <unistd.h>
#include <chrono>
#include <thread>

int main() {
	printf("Hello, World!\n");
        Max7219driver driver;
	while (true)
	{
   		driver.setColour(Max7219driver::colour::red);
		for (int i=0; i<16; i++)
		{
			driver.setIntensity(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		driver.setColour(Max7219driver::colour::blue);
                for (int i=0; i<16; i++)
                {
                        driver.setIntensity(i);
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		driver.setColour(Max7219driver::colour::green);
                for (int i=0; i<16; i++)
                {
                        driver.setIntensity(i);
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
		driver.setColour(Max7219driver::colour::yellow);
                for (int i=0; i<16; i++)
                {
                        driver.setIntensity(i);
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
		driver.setColour(Max7219driver::colour::purple);
                for (int i=0; i<16; i++)
                {
                        driver.setIntensity(i);
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
		driver.setColour(Max7219driver::colour::turqoise);
                for (int i=0; i<16; i++)
                {
                        driver.setIntensity(i);
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
		driver.setColour(Max7219driver::colour::warm);
		for (int i=0; i<16; i++)
		{
			driver.setIntensity(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		driver.setColour(Max7219driver::colour::cold);
		for (int i=0; i<16; i++)
		{
			driver.setIntensity(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		driver.setColour(Max7219driver::colour::white);
		for (int i=0; i<16; i++)
		{
			driver.setIntensity(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
//    		return 0;
	}
}
