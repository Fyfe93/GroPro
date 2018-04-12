// Original LED Trial //

// MAX7221  LED Driver //

#include <iostream>
#include <wiringPiSPI.h>
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

	// Initialise Buffer
	unsigned char buffer [2];

//	while (true){

		// Initialise Test Display and write to PI
		buffer [0] = DISPLAY_TEST;
		buffer [1] = 0x00;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		// Set Data Register to 1 and write to Display register
		buffer [0] = DISPLAY_TEST;
		buffer [1] = 0x01;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		// Set Data Register to 0 and write to Display register to initialise normal operation mode
		buffer [0] = DISPLAY_TEST;
		buffer [1] = 0x00;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		// Power up MAX7221
		buffer [0] = SHUTDOWN;
		buffer [1] = 0x01;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

		// Turning on each segment in the display
		buffer [0] = DECODE_MODE;
		buffer [1] = 0x00;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

		// Set Scan-Limit Register to turn off and on all Digits
        	buffer [0] = SCAN_LIMIT;
        	buffer [1] = 0x07;
        	wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

		//Set Intensity and write to PI
		buffer [0] = INTENSITY; 
		buffer [1] = 0x00;
		wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));


		for(uint8_t i=0; i<9; i++){
			buffer[0] = i;
			buffer[1] = 0x00;
			wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));
		}



		//Setting All on Hopefully
		for (int j=1; j<7; j++)
		{
			printf ("Address Register %i\n\n", j);
	       		for (int i=0; i<256; i++)
			{
		          	buffer [0] = j;
//		        	buffer [1] = (0b00000001 << i);
				buffer [1] = i;
		        	wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));

				printf ("Data Register %i\n\n", i);
				//sleep(1);
				std::this_thread::sleep_for(std::chrono::milliseconds(50));

		 	 }
		}
		
		//Turning all to white
		
//		printf ("Turning all LED's to white\n\n");
//		
//		for (int x=1; x<7; x++){
//			buffer [0] = x;
//			buffer [1] = 0xff;
//			wiringPiSPIDataRW (SPI_CHANNEL, buffer, sizeof (buffer));
//			
//			printf ("Data Register %i\n\n", x);
//			std::this_thread::sleep_for(std::chrono::milliseconds(250));
//		}
//}
}
