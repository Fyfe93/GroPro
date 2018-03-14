![alt text](https://github.com/Fyfe93/GroPro/blob/master/GroProLogo.png)                                     [![alt text](https://github.com/Fyfe93/GroPro/blob/master/Icons/instagram_icon.png)](https://www.instagram.com/groproglasgow/) [<img src="https://github.com/Fyfe93/GroPro/blob/master/Icons/twitter_icon.png" width="40">](https://twitter.com/GroProGlasgow) [<img src="https://github.com/Fyfe93/GroPro/blob/master/Icons/YouTube.png" width="40">](https://www.youtube.com/channel/UC6INIFKsnIOoyIMZFyKa2zQ)

# GroPro
Adaptive Artificial Sunlight Radiator to Provide Optimum Photosynthetic Results in Plant Growing Applications

## Overview

The aim of this project is to design an adaptive lighting system for optimising plant growth. 
It provides improved usability over standard lighting systems that are currently available as the user can control and 
monitor the device from an Android phone application or not interact with device at all during operation due to its 
real-time auto-adjustment protocol. The project is completed in association with the University of Glasgow and is an exercise to gain 
experience with real-time embedded programming.

This project consists of an ambient light sensor that polls brightness values from the environment and then sends this data 
to a Raspberry Pi device for further processing. The output from the Pi is sent to control the intensity of a matrix of 
various LEDs. The system correlates the changes in natural light to a relative output value that controls the LED 
intensity appropriately. The goal is to compensate for the reduction in natural sunlight by increasing the intensity of 
artificial light, therefore continuing to stimulate photosynthesis and thus optimising plant growth.

Olly Warner is responsible for circuit design, all hardware implementation and fabrication. Alasdair Robertson is responsible for the core RPi3 code as well as sensor data aquisition, system evaluation and output to four MAX7219 LED Drivers for RGB LEDs and PWM output for UV & IR LEDs. Andrew Fyfe is responsible for the Android application design, implementation and its integration with the overall system. The time for hardware and software development is divided equally across the team, allowing each component to be completed for the set deadlines. This means that more time is availiable for debugging and construction of the final product.

Regular updates and promotions can be found on our social media pages. 

You can also follow the project's progress, interact with the developers and put forward your ideas for improvements through the above links. Here is a short clip of us demonstrating one of our early RGB demoboards. 

<a href="http://www.youtube.com/watch?feature=player_embedded&v=cS9zusx6LBs
" target="_blank"><img src="http://img.youtube.com/vi/cS9zusx6LBs/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>


## Sensors
Ambient light sensors are used to continually monitor the levels of sunlight available to the plant in question. 
Texas Instruments OPT3001 IC is used as the ambient light sensor, data of which can be accessed through the I2C bus protocol. This data is then processed by the Pi to achieve the desired results. The sensor can process different levels of ambient light every 100ms, which is in excess of our required processing requirements, although is useful for demonstration purposes. The sampling rate for the sensors, therefore, is 10Hz.  

## Processing
The OPT3001 continuously polls data into the RPi3 to adjust the intensity of the LED array, dependent on the level 
of lux the sensor is obtaining from the ambient sunlight. This operates using a PID loop implementation, where the output intensity 
of the LED array will be increased to account for the decrease in light intensity experienced by the OPT3001 during sunset, and 
vice versa for sunrise. Multithreading is also incorporated to allow the RPi3 to "listen" for user interaction with the 
Android app, using this information to adjust the intensity levels of the LED matrix to the user's preference. Therefore, there are two threads implemented in the source code. Classes are used to seperate light sensor data polling and Android application interfacing. External dependencies required for this project include the wiringPi library, in order to access the GPIO pins of the Pi using high level commands, as well as the QT library for the necessary networking protocols. 

The SPI protocol will be used to interface with the MAX7219 LED driver IC. There are four SPI channels implemented along with one I2C channel for communication with the OPT3001 ambient light sensor. The raspberry pi uses the Linux Kernel which is used to compile and run the source code. To reduce noise enduced by the ambient light sensor, post processing is utilised in the form of a 16 sample median filter. This smooths out the sensor's output and surpresses any potential measured fluctuations. Although this may introduce some latency within the processing, it is negligible since instantaneous sensor operation is not fundamental for the success of the product. 

All source code is commited to this GitHub repository. The master branch contains the final release code, the development branch contains the "work in progress" code. There is also an exclusive branch used for the Android application development code. This has been merged with the development branch and is now released to the master branch.  

## Android Application
To provide user control over specific parameters and settings that are of the user's preference, it is necessary to include 
an external application that configures the system appropriately. The application communicates with the Raspberry Pi over a 
local network, manually overriding the system when the user creates parameter changes. Currently the parameters that can be 
set by the user are; Visible LED brightness, UV LED brightness, IR LED brightness and period of sleep. The application is required to respond in realtime to the users interactions, with the PI implementing these instructions at a similar rate. The GUI should operate at a refresh rate of between 24-60fps, which is the Android application standard of operation.    

The Android app is developed using the QT framework in order to allow cross compatibility between mobile operating systems and high level access to the networking protocols. The particular protocol used for this system is a Transmission Controlled Protocol, server-client based.

## LEDs and Hardware Design
The output LED array consists of a mix of UV, RGB and IR LEDs. This is in order to account for as much of the wavespecturm emmited from the sun as possible, where the peak wavelengths within these coincide with those considered "ideal" for plant 
growth. The array is constructed with 76% RGB, 16% IR and 8% UV as this compares well with the relative spectral 
wavelength ratios of natural daylight as calculated from [1,2]. 
The RGB LEDs are driven through the SPI interface of the MAX7219 LED driver IC. This driver allows intensity control through registers and also allows for an efficient PCB layout and easy programming. The UV and IR LEDs are driven through PWM control of a NPN BJT. 
The hardware design is split into four seperate boards, each containing 25 LEDs with their respective drivers. The KiCad files for the schematic, PCB layout and library cache can be found in this GitHub repository.

## Block Diagram

![alt text](https://github.com/Fyfe93/GroPro/blob/master/GroProBlockDiagram_update.png)

## References

[1] Solar Spectral Irradiance, Air Mass 1.5, NREL, 2013

[2] Sole-Source Lighting for Controlled Environment Agriculture, NASA, 2015



