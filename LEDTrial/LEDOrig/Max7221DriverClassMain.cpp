#include <iostream>
#include "Max7221DriverClass.h"
#include <unistd.h>

int main() {
	
	while (true)
	{
		printf("Hello, World!\n");
		Max7219driver driver;
		driver.setColour(Max7219driver::colour::red);
   		for (int i=0; i<16; i++)
		{
			driver.setIntensity(i);
			sleep(1);
		}
		driver.setColour(Max7219driver::colour::blue);
                for (int i=0; i<16; i++)
                {             
                        driver.setIntensity(i);
                        sleep(1);
                }
		driver.setColour(Max7219driver::colour::green);
                for (int i=0; i<16; i++)
                {             
                        driver.setIntensity(i);
                        sleep(1);
                }
		driver.setColour(Max7219driver::colour::yellow);
                for (int i=0; i<16; i++)
                {             
                        driver.setIntensity(i);
                        sleep(1);
                }
		driver.setColour(Max7219driver::colour::purple);
                for (int i=0; i<16; i++)
                {             
                        driver.setIntensity(i);
                        sleep(1);
                }
		driver.setColour(Max7219driver::colour::turqoise);
                for (int i=0; i<16; i++)
                {             
                        driver.setIntensity(i);
                        sleep(1);
                }
    		return 0;
	}
}
