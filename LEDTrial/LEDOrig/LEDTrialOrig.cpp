// Original LED Trial //

// MAX7221  LED Driver //

#include <iostream>
#include <errno.h>
#include <wiringPiSPI.h>
#include <unistd.h>
#include <chrono>
#include <thread>

//SPI Channel is either 0 or 1
//Clock speed for MAX7221 is 10MHz

#define SPI_CHANNEL 0
#define CLOCK_SPEED 10000000

//Define pins

#define DIN         0 // GPIO 17 (WiringPi pin num 0)  header pin 11
#define CS          4 // GPIO 23 (WiringPi pin num 4)   header pin 16

// The Max7219 Registers :

#define DECODE_MODE   0x09
#define INTENSITY     0x0a
#define SCAN_LIMIT    0x0b
#define SHUTDOWN      0x0c
#define DISPLAY_TEST  0x0f

using namespace std;

int main(){
	int fd;

	// Initialise SPI
	fd = wiringPiSPISetup (SPI_CHANNEL, CLOCK_SPEED);
	printf ("Init result %i \n", fd);

	// Set Intensity and write to PI
	unsigned char buffer [2];
	buffer [0] = INTENSITY;
	buffer [1] = 0x01;
	wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

	while (true){

		// Initialise Test Display and write to PI
		buffer [0] = DISPLAY_TEST;
		buffer [1] = 0x00;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

//		sleep (5000);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		// Initialise Shutdown Mode and write to Pi
//		buffer [0] = SHUTDOWN;
		buffer [1] = 0x01;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		buffer [1] = 0x00;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

//		sleep (5000);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
//
		for (char addr=0;addr<8;addr++){
			buffer [0] = addr;
			buffer [1] = addr;
			printf("%i \n", addr);
			wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
}


