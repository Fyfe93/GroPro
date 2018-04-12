#include "OPT.h"

//Constructor
Opt3001::Opt3001()
{
	m_config = 0x10C4;
}

//Deconstructor
Opt3001::~Opt3001()
{
}

//Writing to register
void Opt3001::Write(int addr)
{
	//Initialising wiringPi setup with address of sensor
	m_addr = addr;
	m_fd = wiringPiI2CSetup(addr);
	int write = wiringPiI2CWriteReg16(m_fd, CONF_REG, m_config);
}

//Read Sensor
double Opt3001::Read()
{
	int read = wiringPiI2CReadReg16(m_fd, RES_REG);
	double value = readLux(read);
	return value;
}
