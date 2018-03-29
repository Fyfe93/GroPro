#include "Max7221DriverClass.h"

// Constructor
Max7219driver::Max7219driver()
{
	// Intialsing WiringPiSPI Setup
	int fd = wiringPiSPISetup (SPI_CHANNEL, CLOCK_SPEED);

	// Powering Up MAX7221
	addrRegBuffer [0] = SHUTDOWN;
	addrRegBuffer [1] = 0x01;
	write (addrRegBuffer, bufferSize);

	// Initialise Decode Mode
	addrRegBuffer [0] = DECODE_MODE;
	addrRegBuffer [1] = 0x00;
	write (addrRegBuffer, bufferSize);

	// Setting Scan Limit for all LED's
	addrRegBuffer [0] = SCAN_LIMIT;
        addrRegBuffer [1] = 0x07;
        write (addrRegBuffer, bufferSize);

	// Setting Intensity Full
	setIntensity (15);
}

// Deconstructor
Max7219driver::~Max7219driver()
{
}

//Set Shutdown Mode
void Max7219driver::setAllLedsOn(bool isOn)
{
	if(isOn == true)
	{
		// Powering Up MAX7221
       		addrRegBuffer [0] = SHUTDOWN;
       		addrRegBuffer [1] = 0x01;
        	write (addrRegBuffer, bufferSize);
	}else
	{
		// Powering Up MAX7221
       		addrRegBuffer [0] = SHUTDOWN;
        	addrRegBuffer [1] = 0x00;
        	write (addrRegBuffer, bufferSize);
	}

}


// Reset all LED's
void Max7219driver::reset()
{
	for(uint8_t i=0; i<9; i++)
	{
		addrRegBuffer [0] = i;
		addrRegBuffer [1] = 0x00;
		write (addrRegBuffer, bufferSize);
	}
}

// Intensity Setting Method (0 to 15)
void Max7219driver::setIntensity(int intensityLevel)
{
	addrRegBuffer [0] = INTENSITY;
	addrRegBuffer [1] = intensityLevel;
	write (addrRegBuffer, bufferSize);

}

// Colour setting Method
void Max7219driver::setColour(int colour)
{
	switch(colour)
	{
		//White
		case 0 :
			reset();
			for (int j=1; j<7; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xff;
				write (addrRegBuffer, bufferSize);
			}
			break;
		//Red
		case 1 :
			reset();
			for (int j=1; j<5; j+=3)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xff;
				write (addrRegBuffer, bufferSize);
			}
			break;
		//Green
		case 2 :
			reset();
			for (int j=2; j<6; j+=3)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xff;
				write (addrRegBuffer, bufferSize);
			}
			break;
		//Blue
		case 3 :
			reset();
			for (int j=3; j<7; j+=3)
                        {
                                addrRegBuffer [0] = j;
                                addrRegBuffer [1] = 0xff;
                                write (addrRegBuffer, bufferSize);
                        }
			break;
		//Yellow
		case 4 :
			reset();
			for (int j=1; j<3; j++)
                        {
                                addrRegBuffer [0] = j;
                                addrRegBuffer [1] = 0xff;
                                write (addrRegBuffer, bufferSize);
                        }
			for (int j=4; j<6; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xff;
				write (addrRegBuffer, bufferSize);
			}
			break;
		//Turqoise
		case 5 :
			reset();
			for (int j=2; j<4; j++)
                        {
                                addrRegBuffer [0] = j;
                                addrRegBuffer [1] = 0xff;
                                write (addrRegBuffer, bufferSize);
                        }
                        for (int j=5; j<7; j++)
                        {
                                addrRegBuffer [0] = j;
                                addrRegBuffer [1] = 0xff;
                                write (addrRegBuffer, bufferSize);
                        }
			break;
		//Purple
		case 6 :
			reset();
			for (int j=1; j<4; j+=2)
                        {
                                addrRegBuffer [0] = j;
                                addrRegBuffer [1] = 0xff;
                                write (addrRegBuffer, bufferSize);
                        }
                        for (int j=4; j<7; j+=2)
                        {
                                addrRegBuffer [0] = j;
                                addrRegBuffer [1] = 0xff;
                                write (addrRegBuffer, bufferSize);
                        }
			break;
		//Warm Setting
		case 7 : 
			reset();
			//Digit 0
			for (int j=1; j<2; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xFF;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 1
			for (int j=2; j<3; j++)
			{
				addrRegBuffer [0] = j;	
				addrRegBuffer [1] = 0xF9;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 2
			for (int j=3; j<4; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xD1;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 3
			for (int j=4; j<5; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xF0;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 4
			for (int j=5; j<6; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0x50;
				write (addrRegBuffer, bufferSize); 
			}
			break;
		//Cold Setting
		case 8 :
			reset();
			//Digit 0
			for (int j=1; j<2; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xf1;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 1
			for (int j=2; j<3; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xDB;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 2
			for (int j=3; j<4; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xFD;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 3
			for (int j=4; j<5; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0x40;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 4
			for (int j=5; j<6; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0xA0;
				write (addrRegBuffer, bufferSize);
			}
			//Digit 5
			for (int j=6; j<7; j++)
			{
				addrRegBuffer [0] = j;
				addrRegBuffer [1] = 0x70;
				write (addrRegBuffer, bufferSize);
			}
			break;
		//Default White
		default :
			reset();
			for (int j=1; j<7; j++)
                        {
                                addrRegBuffer [0] = j;
                                addrRegBuffer [1] = 0xff;
                                write (addrRegBuffer, bufferSize);
			}
			break;

	}
}
