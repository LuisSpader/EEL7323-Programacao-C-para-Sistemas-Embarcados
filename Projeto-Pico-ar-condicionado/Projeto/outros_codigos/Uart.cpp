#include <stdio.h>
using namespace std;

class Uart
{
  //
private:
  //
protected:
  //
  char motorWord; // word to be sent to robot
public:
  //
  virtual char sendCommand() = 0;
  virtual void openSerial(int ser) = 0;
  //
  // void setMotor(char cmd);            // Robot.cpp
  //
  // void motorsOff();                   // Robot.cpp
  //
};
/************************************************************
 * File Robot.cpp - Implementation for Robot class
 *
 * The Robot class is an abstract base class.
 * Use the derived classes to create object instances of this class.
 *
 * Project: Fischer Arm
 *
 * Author: Eduardo Augusto Bezerra
 * Date: 04/04/2003
 *
 * Last change: Eduardo Augusto Bezerra
 * Date: 26/04/2003
 *
 * Methods for controlling the robot in C++
 *
 *************************************************************/

// #include "Uart.h"

using namespace std;

/************************************************************
 * void Robot::setMotor(char cmd)
 *
 * Valid commands:
 *
 * a turns base left             00000001
 * d turns base right            00000010
 * s arm goes down               00000100
 * w arm goes up                 00001000
 * o open hand                   00010000
 * c close hand                  00100000
 * 1 turns light on              01000000
 * 0 turns light on (as well)    10000000
 *************************************************************/
/*void Uart::setMotor(char cmd){
   char result;

   switch (cmd){
      case 'a':
      case 'A': {             // left
         motorWord = 0x01;
         break;
      }

      case 'd':
      case 'D': {             // right
         motorWord = 0x02;
         break;
      }

      case 's':
      case 'S': {             // down
         motorWord = 0x04;
         break;
      }

      case 'w':
      case 'W': {             // up
         motorWord = 0x08;
         break;
      }

      case 'o':
      case 'O': {             // open
         motorWord = 0x10;
         break;
      }

      case 'c':
      case 'C': {             // close
         motorWord = 0x20;
         break;
      }

      case '1': {             // light on
         motorWord = 0x40;
         break;
      }

      case '0': {             // light on (as well)
         motorWord = 0x80;
         break;
      }

   }
   result = sendCommand();          // write motor byte to the interface
   motorWord = '0';
}*/

/************************************************************
 * void Robot::motorsOff()()
 *
 * turn off all motors
 *************************************************************/
/*void Uart::motorsOff(){
   char result;
   motorWord = 0;           // reset all
   result = sendCommand(motorWord);          // write motor byte to the interface
}*/
