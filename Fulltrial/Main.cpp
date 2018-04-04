#include <iostream>
#include "Max7221DriverClass.h"
#include "OPT.h"
#include "pid.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

int main(int argc, const char * argv[]) {
	printf("Hello, World!\n");
	PID pid = PID(0.4, 500, 0, 0.1, 0.01, 0.2);
        Max7219driver driver;
	Opt3001 sensor;
	sensor.Write(0x45);
	while (true)
	{
		driver.setColour(Max7219driver::colour::white);
		float lux = sensor.Read();
		printf ("Lux %f\n\n", lux);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		float PIDout = pid.calculate(5000, lux);
		printf ("Pid Pre-Scale %f\n\n", PIDout);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		PIDout = ((PIDout / 33.3));
		PIDout = int (PIDout);
		printf ("Pid Post-Scale %f\n\n", PIDout);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		driver.setIntensity(PIDout);
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}
