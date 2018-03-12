# GroPro
Adaptive Artificial Sunlight Radiator to Provide Optimum Photosynthetic Results in Plant Growing Applications

## Overview

The aim of this project is to design an adaptive lighting system for optimising plant growth. 
It provides improved usability over standard lighting systems that are currently available as the user can control and 
monitor the device from an Android phone application or not interact with device at all during operation due to its 
real-time auto-adjustment protocol. The project is in association with the University of Glasgow and is an exercise to gain 
experience with real-time embedded programming.

This project consists of an ambient light sensor that polls brightness values from the environment and then sends this data 
to a Raspberry Pi device for further processing. The output from the Pi is sent to control the intensity of a matrix of 
various LEDs. The system will correlate the changes in natural light to a relative output value that will control the LED 
intensity appropriately. The goal is to compensate for the reduction in natural sunlight by increasing the intensity of 
artificial light therefore continuing to stimulate photosynthesis and thus optimising plant growth.

Olly Warner will be responsible for circuit design, all hardware implementation and fabrication. Alasdair Robertson will be responsible for the core RPi3 code as well as managing sensor reading, system evaluation and output to MAX72** ICs for RGB LEDs & PWM for UV & IR LEDs, whilst Andrew Fyfe will be responsible for the Android application design and implementation. 

## Sensors
Ambient light sensors will be used to continually monitor the levels of sunlight available to the plant in question. 
Texas Instruments OPT3001 IC will be used as the ambient light sensor, data of which can be accessed through the I2C bus protocol. This data will then be processed by the Pi to achieve the desired results. The sensor can process different levels of ambient light every 100ms, which is in excess of our required processing requirements, but good to have for demonstration purposes. The sampling rate for this project therefore will be 10Hz.  

## Processing
The OPT3001 will continuously be polling data into the RPi3 to adjust the intensity of the LED array dependent on the level 
of lux the sensor is obtaining from the ambient sunlight. This will operate in PID loop fashion, where the output intensity 
of the LED array will be increased to account for the dip in light intensity experienced by the OPT3001 during sunset, and 
vice versa for sunrise. Multithreading will also be incorporated to allow the RPi3 to "listen" for user interaction with the 
android app, using this information to adjust the ratio of the arrays RGB diodes to the users preference. Therefore, there will be two threads implemented in the source code. Classes will be used to seperate light sensor interaction and Android application listening functionality. External dependencies required for this project will include the wiringPi library in order to access the gpio pins of the pin using high level commands as well as the QT library for the necessary networking protocols. The SPI protocol will be used to interface with the MAX72** chip which allows control of multiple LED's at a time. There will be four SPI channels implemented along with one I2C channel for communication with the OPT3001 ambient light sensor. The raspberry pi uses the Linux Kernel which will be using to compile and run the source code. To reduce noise enduced by the ambient light sensor, post processing will be utilised in the form of a 16 sample median filter. This will smooth out the sensors output and surpress any potential measured fluctuations. Although this may introduce some latency within the processing, it will be negligible since instantaneous sensor operation is not fundamental for the success of the product.   

## Android Application
To provide user control over specific parameters and settings that are of the user's preference it is necessary to include 
an external application that configures the system appropriately. The application communicates with the Raspberry Pi over a 
local network, manually overriding the system when the user creates parameter changes. Currently the parameters that can be 
set by the user are; Visible LED brightness, UV LED brightness, IR LED brightness and period of sleep. The application is required to respond in realtime to the users interactions, with the PI implementing these instructions at a similar rate. The GUI should operate at a refresh rate of 60fps, which is the android application standard of operation.    

## LEDs and Hardware Design
The output LED array will consist of a mix of UV, RGB and IR LEDs. These have been selected so that as much of the sunlight 
spectrum as possible can be covered, where the peak wavelengths within these coincide with those considered "ideal" for plant 
growth. The array will be constructed with 76% RGB, 16% IR and 8% UV as this compares well with the relative spectral 
wavelength ratios of natural daylight as calculated from [1,2]. The array will be driven through an external power source due 
to the number of LEDs being used and the intensity of each LED will be controlled through a PWM driving a BJT and also with 
LED driver ICs.

## Block Diagram

![alt text](https://github.com/Fyfe93/GroPro/blob/master/GroProBlockDiagram.png)

## References

[1] Solar Spectral Irradiance, Air Mass 1.5, NREL, 2013

[2] Sole-Source Lighting for Controlled Environment Agriculture, NASA, 2015



