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

## Sensors
Ambient light sensors will be used to continually monitor the levels of sunlight available to the plant in question. 
Texas Instruments OPT3001 IC will be used as the ambient light sensor, data of which can be accessed through I2C. 
This data will then be processed by the Pi to achieve the desired results.

## Processing
The OPT3001 will continuously be polling data into the RPi3 to adjust the intensity of the LED array dependent on the level 
of lux the sensor is obtaining from the ambient sunlight. This will operate in PID loop fashion, where the output intensity 
of the LED array will be increased to account for the dip in light intensity experienced by the OPT3001 during sunset, and 
vice versa for sunrise. Multithreading will also be incorporated to allow the RPi3 to "listen" for user interaction with the 
android app, using this information to adjust the ratio of the arrays RGB diodes to the users preference.

## Android Application
To provide user control over specific parameters and settings that are of the user's preference it is necessary to include 
an external application that configures the system appropriately. The application communicates with the Raspberry Pi over a 
local network, manually overriding the system when the user creates parameter changes. Currently the parameters that can be 
set by the user are; Visible LED brightness, UV LED brightness, IR LED brightness and period of sleep.

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



