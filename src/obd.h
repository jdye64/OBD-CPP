//
// Created by Jeremy Dyer on 9/5/17.
//

#ifndef OBD_CPP_OBD_H
#define OBD_CPP_OBD_H

#include <iostream>
#include "OBDResponse.h"
#include "elm327.h"

/**
Class representing an OBD-II connection
with it's assorted commands/sensors.
*/
class obd {

 public:

  obd(){
    std::cout << "Creating OBD object" << std::endl;
    _fast = true;
    _lastCommand = 0;
  }

  // Destructor
  virtual ~obd() {
  }

  // Attempts to instantiate an ELM327 connection object
  void connect(char *portStr, int baudrate);

  OBDResponse query(char *cmd);

 protected:
  char *_portStr;      // Identifier for the serial port connection
  int _baudRate;       //baudrate for the serial connection
  int _commands[7];  // Only 7 commands supported by elm327 interface
  bool _fast;        // Global switch for running optimizations
  int _lastCommand;   // Last command used for running previous command.

 private:
  char* buildCommandString(char *cmd);
  elm327 _elm;
};

#endif //OBD_CPP_OBD_H
