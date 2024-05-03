# AsimUFF Mini-Sumo Robot

## Introduction
The AsimUFF Mini-Sumo Robot's source code and documentation, developed at UFF, are housed in this repository. Equipped with advanced sensors and motors, it's crafted for competing in mini-sumo tournaments.

## Components

- 2 x DRV8833 H-Bridge Motor Drivers (one for each motor)
- 2 x N20 Micro Motors
- 3 x QRE1113 Line Sensors
- 5 x JS40F Distance Sensors
- Microstart
- 4-position DIP Switch
- Arduino Micro

## Directory Structure

- `tests`: Contains test scripts to verify the functionality of individual components.
  - `constants.h`: Header file with constants used in test scripts.
  - `tests.ino`: Arduino sketch for running component tests.
  
- `minisumo`: Main directory for the robot's operational code.
  - `constants.h`: Header file with constants used across multiple modules.
  - `minisumo.ino`: Main Arduino sketch for the robot's operation.
  - `motors.cpp` & `motors.h`: Control logic for the motors.
  - `sensors.cpp` & `sensors.h`: Integration and management of sensor data.
  - `strategies.cpp` & `strategies.h`: Decision-making algorithms for competition.

## Setup & Installation
To set up and run the Mini-Sumo Robot, follow these steps:

1. Ensure all components are correctly wired according to PINS.
2. Install the Arduino IDE from the [official website](https://www.arduino.cc/en/software).
3. Clone this repository to your local machine.
4. Open the `minisumo.ino` file with the Arduino IDE.
5. Compile and upload the sketch to your Arduino Micro.

## Testing
Before competing, it's essential to test each component and functionality of the robot:

1. Navigate to the `tests` directory.
2. Open and upload the `tests.ino` sketch to the Arduino.

## Acknowledgments
- Special thanks to everyone who has contributed to the project.
- This project was inspired by [Sumo Boy Channel](https://www.youtube.com/@sumoboy737) and [MinervaBots](https://github.com/MinervaBots/ZePequeno).
