#include <wiringPiSPI.h>
#include <thread>

//SPI Channel is either 0 or 1
//Clock speed for MAX7219 is 10MHz

#define SPI_CHANNEL 0
#define CLOCK_SPEED 10000000

//Define Max7221 Registers

#define DIGIT_0      0x01
#define DIGIT_1      0x02
#define DIGIT_2      0x03
#define DIGIT_3      0x04
#define DIGIT_4      0x05
#define DIGIT_5      0x06
#define DIGIT_6      0x07
#define DIGIT_7      0x08
#define DECODE_MODE  0x09
#define INTENSITY    0x0a
#define SCAN_LIMIT   0x0b
#define SHUTDOWN     0x0c
#define DISPLAY_TEST 0x0f

class Max7219driver
{
public:
	Max7219driver(); // Initial LED driver setup, SPI setup
	~Max7219driver();
	void setColour(int colour); // Sets colour of LEDs given in enum
	void setIntensity(int  intensityLevel); // Sets Intensity of LEDs
	void setAllLedsOn(bool isOn); // Turns On/Off LEDs
	void reset(); // Writes each LED state to zero
    
    // List of colours that can be created by the LEDs
	enum colour
	{
		white = 0,
		red,
		green,
		blue,
		yellow,
		turqoise,
		purple,
		warm,
		cold
	};

private:

	unsigned char  addrRegBuffer[2]; // Contains the Address and data that is sent to the LED driver
	int bufferSize {2};
    
    //Writes Address and Data registers to all Driver chips
	void write(unsigned char* addrRegBuffer, size_t bufferSize)
    {
        unsigned char tempAddrBuffer[8];
        tempAddrBuffer[0] = addrRegBuffer[0];
        tempAddrBuffer[1] = addrRegBuffer[1];
        tempAddrBuffer[2] = addrRegBuffer[0];
        tempAddrBuffer[3] = addrRegBuffer[1];
        tempAddrBuffer[4] = addrRegBuffer[0];
        tempAddrBuffer[5] = addrRegBuffer[1];
        tempAddrBuffer[6] = addrRegBuffer[0];
        tempAddrBuffer[7] = addrRegBuffer[1];
        
        wiringPiSPIDataRW(SPI_CHANNEL, tempAddrBuffer, sizeof (tempAddrBuffer));

	}

};
