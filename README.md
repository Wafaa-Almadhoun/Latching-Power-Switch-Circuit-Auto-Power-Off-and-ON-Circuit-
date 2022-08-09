# Latching-Power-Switch-Circuit-(Auto-Power-Off-and-ON-Circuit)


## Table of contents
* [Introduction](#Introduction)
* [Overview](#Overview)
* [Technologies](#technologies)
* [Components required](#Components-required)
* [Connections](#Connections)
* [Simulation ](#simulation)



## Introduction
    
    This project allows you to cut off power completely when the microcontroller is not executing any task. 
    In other words, as soon as the microcontroller finishes executing a task it turns itself off via software ,
    after that you can power on the circuit if detects any input by sensors ,This is a great way to make batteries
    last longer in your electronics projects.
    
## Overview

      *  When you press the circuit’s pushbutton , there is power driven to the microcontroller. So, your Arduino turn on.
 
      *  You set the LATCH pin (set in the code) to HIGH to keep the circuit powered on.
 
      *  The microcontroller executes its tasks. In our example, the LED blink 3 times then waits 15 seconds.
  
      *  Set the LATCH pin to LOW, so the microcontroller auto powers off .
  
      *  When the LATCH pin is set to LOW, the power is cut off.

      *  while if there any inputs by the sensor in our case vibration sensor the circuit turn on the Arduino 
          and repet the steps back again .
   






## Technologies
Project is created with:
* Arduino IDE 1.8.19 [To Downloud](https://www.arduino.cc/en/software)
	
## Components required

     1. Arduino UNO
     2. 1 x IRF4905 P-MOSFET
     3. jumper wirs
     4. 1 x 2N3904 Transistor BJT NPN
     5. bettrey  6 V 
     6. breadboard
     7. Resistors:2x 220K Ohm, 2x 100K Ohm, 10K Ohm, and 220 Ohm
     8. 2x Diodes 1N5819
     9. Pushbutton  12x12x7
    10. Vibration sensor module
    11. Relay module One channel 5V-10A
    12. LED 5mm 
    

    
## Connections

![Fritzing_bb](https://user-images.githubusercontent.com/64277741/183543889-9688e3a1-882f-4789-94d7-627acc1c9e2e.png)

Figure (1): circuit connection

![real circuit](https://user-images.githubusercontent.com/64277741/183540015-e4d828d8-7902-4c58-b0f3-c5e95596a806.jpg)
Figure (2): circuit connection
     
## Simulation

I made short video for show the output  [to see here ](https://youtu.be/_LIZAVPyHyI)


#### The Code 
 

// Define power latch pin  Arduino (Digital 5)

const int powerLatch = 5;

#define LED_PIN 9

void setup() {

  // Define pin as an OUTPUT
  
  pinMode(powerLatch, OUTPUT); 
  
  
  // Keeps the circuit on
  
  digitalWrite(powerLatch, HIGH);
  
  delay(1000);
  
  pinMode(LED_PIN, OUTPUT);
  
  digitalWrite(LED_PIN, HIGH);
  
  delay(1000);
  
  digitalWrite(LED_PIN, LOW );
  
  delay(1000);
  
  digitalWrite(LED_PIN, HIGH);
  
  delay(1000);
  
  digitalWrite(LED_PIN, LOW );
  
  delay(1000);
  
  digitalWrite(LED_PIN, HIGH);
  
  delay(1000);
  
  digitalWrite(LED_PIN, LOW );
  
  delay(15000);
  
  // Turns the power latch circuit off
  
  digitalWrite(powerLatch, LOW);
}

void loop() {

 
}
