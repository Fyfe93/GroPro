#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <cmath>

//Defining Configuration and Results Register

#define CONF_REG 0x01
#define RES_REG 0x00

class Opt3001
{
public:
	Opt3001(); //  Sensor setup, I2C setup
	~Opt3001();
	void Write(int addr); // Writes to sensor registers over I2C
	float Read(); // Reads value provided by sensor from sensor data register

private:

//Defining global variables
	int m_config;
	int m_addr;
	int m_fd;

//Lux Conversion
	float readLux(int readres)
	{
		int left = readres&0xFF; 
		left = left << 8;
		int right = readres&0xFF00;
		right = right >> 8;
		readres = (left|right);

		int exponential = readres&0b1111000000000000;
		exponential = exponential >> 12;
		float LSB_Size=pow(2, exponential)*0.01;
		int R = readres&0b0000111111111111;
		return R*LSB_Size;
	}
};
