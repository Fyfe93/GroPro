#include "Max7221DriverClass.h"
#include <wiringPiSPI.h>
#include <assert.h>
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>

//UNIT TEST FOR MAX7219 Driver Class

int main(void){
  int passed = 0;
  int totaltest = 5;
  bool test_success;
  Max7219driver *Maxdrivertest;
  std::ifstream enableFile;
  std::string enableFileName;

  //Testing LED Driver Constructor
  test_success = true;
  try { Maxdrivertest = new Max7219driver();}
  catch(std::exception& e) {test_success=false;}
  assert(test_success);
  passed++;
  delete Maxdrivertest;

  //Testing All LED's On Function
  test_success = true;
  try { Maxdrivertest = new Max7219driver();
    Maxdrivertest->setAllLedsOn(true);
  }
  catch(std::exception& e) {test_success=false;}
  assert(test_success);
  passed++;
  delete Maxdrivertest;

  //Testing LED's Reset Function
  test_success = true;
  try { Maxdrivertest = new Max7219driver();
    Maxdrivertest->reset();
  }
  catch(std::exception& e) {test_success=false;}
  assert(test_success);
  passed++;
  delete Maxdrivertest;

  //Testing LED's setIntensity Function
  test_success = true;
  try { Maxdrivertest = new Max7219driver();
    Maxdrivertest->setIntensity(15);
  }
  catch(std::exception& e) {test_success=false;}
  assert(test_success);
  passed++;
  delete Maxdrivertest;

  //Testing LED's setColour Function
  test_success = true;
  try { Maxdrivertest = new Max7219driver();
    Maxdrivertest->setColour(Max7219driver::colour::red);
  }
  catch(std::exception& e) {test_success=false;}
  assert(test_success);
  passed++;
  delete Maxdrivertest;

  //Results
	std::cout << "Results: " << passed << " out of " << totaltest << " tests were successful!\n";
}
