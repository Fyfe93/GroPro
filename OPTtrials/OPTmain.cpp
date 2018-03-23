#include <iostream>
#include "OPT.h"
#include <unistd.h>
#include <chrono>
#include <thread>

int main() {
	Opt3001 Sensor;
	Sensor.Write(0x45);
	while (true){
		float lux = Sensor.Read();
		printf ("lux %f\n\n", lux);
	}
}
