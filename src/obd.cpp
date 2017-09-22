#include "obd.h"
#include "elm327.h"


// Attempts to instantiate an ELM327 connection object
void obd::connect(char *portStr, int baudrate) {
  if (!portStr) {
    std::cout << "Serial port identifier is not specified. Exiting application now!" << std::endl;
    exit (-1);
  }

  _baudRate = baudrate;
  _portStr = portStr;
  std::cout << "Using Serial Port: " << portStr << std::endl;
  std::cout << "Using Baudrate: " << baudrate << std::endl;

  // Create the ELM327 interface connection
  _elm = elm327(portStr, baudrate);

//  std::cout << "Querying car with 010C Engine RPM" << std::endl;
//  while (true) {
//    Message m = elm._send_and_parse("010C");
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//  }

}

OBDResponse obd::query(char *cmd) {

  if (_elm.getOBDStatus() == NOT_CONNECTED) {
    std::cout << "ERROR: Query failed. ELM not connected!" << std::endl;
    return OBDResponse();
  }

  std::cout << "Sending CMD: " << cmd << std::endl;
  char* cmdStr = this->buildCommandString(cmd);
  Message message = _elm._send_and_parse(cmdStr);
  
}

// Creates the appropriate command string to send to the elm327 interface
char* obd::buildCommandString(char *cmd) {
  return cmd;
}
