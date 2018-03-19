//
//  main.cpp
//  pidExample
//
//  Created by Andrew Fyfe on 19/03/2018.
//  Copyright © 2018 Andrew Fyfe. All rights reserved.
//

#include "pid.h"
#include <stdio.h>
#include <iostream>

int main(int argc, const char * argv[])
{
    
    PID pid = PID(0.1, 100, -100, 0.1, 0.01, 0.5);
    
    double val = 20;
    for (int i = 0; i < 100; i++) {
        double inc = pid.calculate(0, val);
        printf("val:% 7.3f inc:% 7.3f\n", val, inc);
        val += inc;
    }
    
    return 0;
}

    

