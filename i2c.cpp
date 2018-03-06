#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

#define CONF_REG 0x01
#define RES_REG 0x00

//life

float lux(int fd){
	int readres = wiringPiI2CReadReg16(fd, RES_REG);
	int exponential = readres&0b1111000000000000;
	exponential = exponential >> 12;
	float LSB_Size=pow(2, exponential)*0.01;
	int R = readres&0b0000111111111111;
	return R*LSB_Size;
}

int main(int argc, const char * argv[]){
	int data = 0b1100110011101010;
	int fd = wiringPiI2CSetup(0x44);

	while  (true) {
		int write = wiringPiI2CWriteReg16(fd, CONF_REG, data);
//		std::cout <<  write << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		float lux_ = lux(fd);
		printf ("lux %f\n", lux_);			
	}
}
