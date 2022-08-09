# Latching-Power-Switch-Circuit-(Auto-Power-Off-and-ON-Circuit)


## Table of contents
* [Introduction](#Introduction)
* [Overview](#Overview)
* [Technologies](#technologies)
* [Components required](#Components-required)
* [Connections](#Connections)
* [Block diagram & simulation ](#Block-diagram-&-simulation)



## Introduction
    
    This project allows you to cut off power completely when the microcontroller is not executing any task. 
    In other words, as soon as the microcontroller finishes executing a task it turns itself off via software ,
    after that you can power on the circuit if detects any input by sensors ,This is a great way to make batteries
    last longer in your electronics projects.
    
## Overview
  


## Technologies
Project is created with:
* Arduino IDE 1.8.19 [To Downloud](https://www.arduino.cc/en/software)
* Proteus [To Downloud](https://www.labcenter.com/simulation/)
	
## Components required
### 1. Unipolar Stepper with ULN2003 
    1. Arduino UNO
    2. 1 – 28BYJ-48 Unipolar Stepper
    3. jumper wirs
    4. driver board ULN2003
    5. bettrey  5 and 12 volt 
    6. breadboard
    
### 2. Bipolar Stepper with L293D Motor Driver IC
    1. Arduino UNO
    2. 1  NEMA 17 bipolar stepper
    3. jumper wirs
    4. L293D Motor Driver IC
    5. bettrey  5 and 12 volt 
    6. breadboard
    
### 3. BIG Stepper Motors NEMA 23 Bipolar with DM860A Microstep Driver .
    1. Arduino UNO
    2. 1  NEMA 23 bipolar stepper
    3. jumper wirs
    4. DM860A Microstep Driver
    5. bettrey 24 volt 
    6. breadboard
    7. push button 
    8. 10 k ohm
    9. potentiometer
    
## Connections

### 1. Unipolar Stepper with ULN2003

     connecting ULN2003 pin1 to pin 8 in Ardunio
     connecting ULN2003 pin2 to pin 9 in Ardunio
     connecting ULN2003 pin3 to pin 10 in Ardunio
     connecting ULN2003 pin4 to pin 11 in Ardunio
     connecting ULN2003 pin16 to pin1 in stepper
     connecting ULN2003 pin15 to pin2 in stepper
     connecting ULN2003 pin14 to pin3 in stepper
     connecting ULN2003 pin13 to pin4 in stepper
     connecting ULN2003 pin9 and the 2 2VDD pin in stepper motor to 12v battery 
     Connect ground to ground
     
 ### 2. Bipolar Stepper with L293D Motor Driver IC
 
    connecting 5V output on Arduino to the Vcc2 & Vcc1 pins
    
    Connect ground to ground.
    
    connect the input pins(IN1, IN2, IN3 and IN4) of the L293D IC to 
    
    four digital output pins(12, 11, 10 and 9) on Arduino
    0ne coil of stepper moter connecting to Out1 & Out2 and the anthor coil connecting to Out3 & Out4
    
 
 ### 3. BIG Stepper Motors NEMA 23 Bipolar with DM860A Microstep Driver 
 
     connecting pin6 in Ardunio to -DIR in DM860A 
     connecting pin7 in Ardunio to -PUL in DM860A
     connecting +5v output in Ardunio to +PUL & +DIR in DM860A
     connecting pin2 in Ardunio to one side of push button and also the 10 K ohm resistor connection up to the +5v on the arduino 
     connecting GND in Ardunio to the other side of push button
     connecting GND in Ardunio to the one side of potentiometer
     connecting +5v in Ardunio to the other side of potentiometer
     connecting pin A0 in Ardunio to the signal of potentiometer
     connecting the motor driver with 24v battery
     connecting the pin A+ driver with A+ in DM860A
     connecting the pin A- driver with A- in DM860A
     connecting the pin B+ driver with B+ in DM860A
     connecting the pin B- driver with B- in DM860A

     
## Block diagram & simulation
### 1. Unipolar Stepper with ULN2003 . [see here](https://github.com/Wafaa-Almadhoun/Stepper-motor-using-Arduino-UNO-R3-/blob/main/stepper%20using%20ULN2003.pdsprj)
##### Slow - 4-step CW sequence to observe lights on driver board
![1](https://user-images.githubusercontent.com/64277741/179306291-f9684758-deaf-4828-9520-757a142ba537.PNG)
Figure (1): Stepper Motor at 90 degree after 1-step CW sequence
![2](https://user-images.githubusercontent.com/64277741/179307189-82e1089f-4cbb-403a-b78c-a4c990c24522.PNG)
Figure (2): Stepper Motor at 180 degree after 2-step CW sequence
![3](https://user-images.githubusercontent.com/64277741/179307421-bbcf698d-139f-4d30-aae9-9546c057fb68.PNG)
Figure (3): Stepper Motor at 270 degree after 3-step CW sequence
![4](https://user-images.githubusercontent.com/64277741/179307644-0f9d39bf-591d-45a1-b9c4-d38ec8528d7d.PNG)
Figure (4): Stepper Motor at 342 degree after 4-step CW sequence
##### Rotate CW 1/2 turn slowly
![5](https://user-images.githubusercontent.com/64277741/179308867-85dbccdc-5070-4164-82c7-9776d4b09fc9.PNG)
Figure (5): Rotate CW 1/2 turn slowly
##### Rotate CCW 1/2 turn quickly
![6](https://user-images.githubusercontent.com/64277741/179309329-1eed85e5-3f0d-48a3-b2be-3d9a40e71869.PNG)
Figure (6): Rotate CCW 1/2 turn quickly

#### The Code 
 Demonstrates 28BYJ-48 Unipolar Stepper with ULN2003 Driver
 
  Uses Arduino Stepper Library
 
//Include the Arduino Stepper Library

#include <Stepper.h>
 
// Define Constants
 
// Number of steps per internal motor revolution 

const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction

const float GEAR_RED = 64;
 
// Number of steps per geared output rotation

const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
 
// Define Variables
 
// Number of Steps Required

int StepsRequired;
 
// Create Instance of Stepper Class

// Specify Pins used for motor coils

// The pins used are 8,9,10,11 

// Connected to ULN2003 Motor Driver In1, In2, In3, In4 

// Pins entered in sequence 1-3-2-4 for proper step sequencing
 
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);
 
void setup()
{

// Nothing  (Stepper Library sets pins as outputs)

}
 
void loop()
{

  // Slow - 4-step CW sequence to observe lights on driver board
  
  steppermotor.setSpeed(1);    
  
  StepsRequired  =  4;
  
  steppermotor.step(StepsRequired);
  
  delay(2000);
 
   // Rotate CW 1/2 turn slowly
   
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  
  steppermotor.setSpeed(100);   
  
  steppermotor.step(StepsRequired);
  
  delay(1000);
  
  // Rotate CCW 1/2 turn quickly
  
  StepsRequired  =  - STEPS_PER_OUT_REV / 2;   
  
  steppermotor.setSpeed(700);  
  
  steppermotor.step(StepsRequired);
  
  delay(2000);
 
}

### 2. Bipolar Stepper with L293D Motor Driver IC .[see here ](https://github.com/Wafaa-Almadhoun/Stepper-motor-using-Arduino-UNO-R3-/blob/main/Bipolar%20Stepper%20with%20L293D%20Motor%20Driver%20IC.pdsprj)
![1](https://user-images.githubusercontent.com/64277741/179328636-268173e6-09b8-46fb-9431-1dfe2eae640f.PNG)
Figure (7): step one revolution in the other direction ("counterclockwise")

 ![2](https://user-images.githubusercontent.com/64277741/179328701-3dee3532-ada8-4ae9-abdd-f15dcee8762f.PNG)
Figure (8): step one revolution in one direction ("clockwise")

#### The code 

// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation NEMA 17

const int stepsPerRevolution = 200; 

// Create Instance of Stepper library

Stepper myStepper(stepsPerRevolution, 12, 11, 10, 9);


void setup()
{
  // set the speed at 20 rpm:
  
  myStepper.setSpeed(20);
  
}

void loop() 
{
  // step one revolution in one direction:
  
  myStepper.step(stepsPerRevolution);
  
  delay(1000);

  // step one revolution in the other direction:
  
  myStepper.step(-stepsPerRevolution);
  
  delay(1000);
}


### 3. BIG Stepper Motors NEMA 23 Bipolar with DM860A Microstep Driver  
![3BIG Stepper Motors NEMA 23 Bipolar with DM860A Microstep Driver](https://user-images.githubusercontent.com/64277741/179338072-d89222ff-f4ea-4005-a69e-4427b546f48d.png)

#### The Code 
// Defin pins
 
int reverseSwitch = 2;  // Push button for reverse
int driverPUL = 7;    // PUL- pin
int driverDIR = 6;    // DIR- pin
int spd = A0;     // Potentiometer
 
// Variables
 
int pd = 500;       // Pulse Delay period
boolean setdir = LOW; // Set Direction
 
// Interrupt Handler
 
void revmotor (){
 
  setdir = !setdir;
  
}
 
 
void setup() {
 
  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(reverseSwitch), revmotor, FALLING);
  
}
 
void loop() {
  
    pd = map((analogRead(spd)),0,1023,2000,50);
    digitalWrite(driverDIR,setdir);
    digitalWrite(driverPUL,HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL,LOW);
    delayMicroseconds(pd);
 
}

