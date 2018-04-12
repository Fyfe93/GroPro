#include <iostream>
#include "Max7221DriverClass.h"
#include "OPT.h"
#include "pid.h"
#include <unistd.h>
#include <chrono>
#include <thread>

int main(int argc, const char * argv[]) {
	printf("Hello, World!\n");
	PID pid = PID(0.4, 500, 0, 0.05, 0.1, 0.001);
	Max7219driver driver;
	Opt3001 sensor;
	sensor.Write(0x45);
	printf("Worked before while loop\n");
	while (true)
	{
		driver.setColour(Max7219driver::colour::white);
		float lux = sensor.Read();
//		printf ("Lux %f\n\n", lux);
//		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		float PIDout = pid.calculate(3000, lux);
//		printf ("Pid Pre-Scale %f\n\n", PIDout);
//		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		PIDout = ((PIDout / 33.3));
		PIDout = int (PIDout);
//		printf ("Pid Post-Scale %f\n\n", PIDout);
//		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		driver.setIntensity(PIDout);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
