//
//  main.cpp
//  pidExample
//
//  Created by Andrew Fyfe on 19/03/2018.
//  Copyright © 2018 Andrew Fyfe. All rights reserved.
//

#include "pid.h"
#include "OPT.h"
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, const char * argv[])
{

    PID pid = PID(0.1, 1000, -1000, 0.1, 0.01, 0.4);
    Opt3001 sensor;
    sensor.Write(0x45);

    double val = 20;
    while (true) {
	float lux = sensor.Read();
        float inc = pid.calculate(5000, lux);
        printf("val:% 7.3f inc:% 7.3f\n", lux, inc);
//        val += inc;
	inc = (inc / 62.5);
	printf("increment post scale %f\n\n", inc);
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    return 0;
}

