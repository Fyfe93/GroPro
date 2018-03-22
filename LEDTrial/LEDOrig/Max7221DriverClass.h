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
	Max7219driver();
	~Max7219driver();
	void setColour(int colour);
	void setIntensity(int  intensityLevel);
	void setAllLedsOn(bool isOn);
	void reset();

	enum colour
	{
		white = 0,
		red,
		green,
		blue,
		yellow,
		turqoise,
		purple
	};

private:

	unsigned char  addrRegBuffer[2];
	int bufferSize {2};

	void write(unsigned char* addrRegBuffer, size_t bufferSize)
	{
		for (int i = 0; i < 4; i++)
		{
			wiringPiSPIDataRW(SPI_CHANNEL, addrRegBuffer, sizeof (addrRegBuffer));
			addrRegBuffer[0] = addrRegBuffer[0] << 4;
			addrRegBuffer[1] = addrRegBuffer[1] << 4;
		}

	}

};
