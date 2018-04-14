#include "OPT.h"
#include <assert.h>
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

//UNIT TEST FOR OPT3001 AMBIENT LIGHT SENSOR
static const int OPT_ADDRESS = 0x45;

int main(void){

	int passed = 0;
	int totaltest = 2;
	float val;
	int maxlux = 90000;
	bool test_success;
	Opt3001 *OptTest;
	std::ifstream enableFile;
    	std::string enableFileName;
	
	//Testing Write to Sensor
	test_success = true; 
	try { OptTest = new Opt3001();
		OptTest->Write(OPT_ADDRESS);
	} 
	catch(std::exception& e) {test_success=false;}
	assert(test_success);
	passed++;
	delete OptTest;

        //Testing Write to Sensor
	test_success = true;
	try { OptTest = new Opt3001();
		val = OptTest->Read();
	}
	catch(std::exception& e) {test_success=false;}
	if (val < 0 || val >= maxlux){
		throw std::out_of_range("Error: Sensor reading out of range");
	}
	assert(test_success);
	passed++;
	delete OptTest;

	//Results
	std::cout << "Read Sensor value: " << val << " lux" << std::endl;
	std::cout << "Results: " << passed << " out of " << totaltest << " tests were successful!\n";
}
