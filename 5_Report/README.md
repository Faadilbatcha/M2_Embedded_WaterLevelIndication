# Introduction:
In our daily life Water plays a vital role. The Availability of water in tank is one of the important parameter for every Household. If the Water level in tank is too low, Device must turn on the motor. Else if the level reaches high, Device must turn off the Motor. Since Water is the most essential thing, if the level's abnormal It disrupts the daily household chores. So we should maintain the Water level constantly.

# ABSTRACT
## WATER LEVEL INDICATION 
  A water level indicator is a system that relays information back to a control panel to indicate whether a body of water has a high or low water level. Some water level indicators use a combination of probe sensors or float switches to sense water levels. “The Water Level Indicator employs a simple mechanism to detect and indicate the water level in an overhead tank or any other water container.” according to Electronics Hub.

## PURPOSE OF WATER LEVEL INDICATION 
  The purpose of a water level indicator is to gauge and manage water levels in a water tank. The control panel can also be programmed to automatically turn on a water pump once levels get too low and refill the water back to the adequate level.

## WATER LEVEL INDICATION SENSOR ?
  A water level indicator sensor, also known as a probe sensor, is what tells the control panel that corrective action is needed. A combination of high and low sensors are used to tell the control panel when water levels are too high or too low. The control panel will then automatically turn the pump on or off depending on the corrective action needed. Here in our porject, we are actually using Ultrasonic sensor to determine the Water level and to  otify the Controller inspite Probe sensor.
  
## WORKING PRINCIPLE 
  The working principle of a water level indicator is actually quite simple. Water level indicators work by using Ultrasonic Sensor to indicate water levels in a storage tank. These Sensors send information back to the control panel to trigger an alarm or indicator(LED). As mentioned above, the control panel can be programmed to automatically turn on your pump to refill the water again thereby Alerting the user via Bluetooth Sensor.
* The water level is full – Indicate High level, Send Alert message.
* Water level drops to the low level – Indicator LED is triggered.
* Motor is triggered automatically turning on the water to fill the tank
* Once the water is full, fill stop is triggered and the system automatically stops the Motor.
* The system resets and waits for water levels to drop again.

## APPLICATIONS 
Applications of a Water Level Indicator: 
Water level indicators can be used in Hotels, Pools, Factories, fire protection systems in buildings and more. Other applications and uses of a water level indicator include:
* Hotels
* Home apartments
* Commercial complexes
* Factories
* Where cooling towers are used
* Residential and commercial swimming pools
* Anywhere water levels need to be controlled
* Bore wells
* Sump Pumps
* Used to start and stop water pumps
* Water level indicator for water tank

# Features:
1.Detects the Water level in the tank and Manipulate the Motor state with respect to the level with alerting the User via Bluetooth module.

2.Available in low cost and in smaller sizes.

3.Simple circuit design and easy to understand.

# 4W'S and 1H:
## What?
* It is a Motor control based project which detects the Tank's water level and gives an alert over the Level and Motor State to the User.
## WHY?
* Its a good habit to keep our Daily water usage normal and also it is very needed for everyone to know the need of saving water so the devices like ours will be a first step in Saving water and electricity in every households. 
## WHERE?
* We can use it in every Households, Offices and also every Water needed Sectors.
## WHO?
*  It is an automated detector, So no need for any manual involvement to reset to normal value so every one who needs can use it.
## HOW?
* A sensor which is the main part of this project, It is the one which detects and transmits the value.

# SWOT ANALYSIS:
## Strength:
- Its strength is compact in size.
- Accuracy in displaying the correct Water Level.
- Automated Motor control.
- Cost efficient.
## Weakness:
- Due to the usage of electronic components in a Water Reserve, we need to be very careful in creating a Water-resistant environment.
## Opportunity:
- We should create an opportunity to make our product used by everyone by providing an awareness over the wastage of water and electricity due to less user attention and importance of surveiling the Motor for atmost care.
- Due to current Water demanding situation now it is needed everywhere in the world.
## Threat:
- Now there are many new developing devices for competition in the Water level Indication sector.


# REQUIREMENTS:
## High level requirements:
| S.no | High level requirement | Description | Status |
| :---:| :---: | :---: | ---: |
| 1 | HLR1 |  Atmega328 | Done |
| 2 | HLR2 | Sensor | Done |
| 3 | HLR3 | Alert system | Done |

## Low level requirements:
| S.no | Low level requirements | Description | Status |
| :---: | :---: | :---: | ---: |
| 1 | LR1 | Simulide | Done |
| 2 | LR2 | Avr Gcc compiler | Done |
| 3 | LR3 | LED Indication | Done |

# BLOCK DIAGRAM - Water Level Indication
![image](https://user-images.githubusercontent.com/101641134/164181128-1bf5cc25-5e2c-4737-aecc-d0003a6727f8.png)

# FLOW CHART - Water Level Indication
![image](https://user-images.githubusercontent.com/101641134/164177036-d3daba76-939e-4fba-b47a-41acf9dbf3d6.png)

# Simulation Circuit
![image](https://user-images.githubusercontent.com/101641134/163779150-7d473f7b-c36c-4fea-bb80-73889ebd1bfb.png)

# Test Plans

| **Test ID** | **Description** | **Input** | **Output** | **Status** |
| --- | --- | --- | --- | --- |
| TID\_01 | Ultrasonic distance detected | - | Distance | PASS ||
| TID\_02 | Processed by the controller | Distance | Level | PASS |
| TID\_03 | Low Level | A | Turn Motor On, Send Alert | PASS |
| TID\_04 | High Level | B | Turn Motor Off, Send Alert | PASS |
| TID\_06 | Display | Levels | Process states & Message Alerts | PASS |
