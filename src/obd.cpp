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
  elm327 elm(portStr, baudrate);

  std::cout << "Querying car with 010C Engine RPM" << std::endl;
  Message m = elm._send_and_parse("010C");
  std::cout << "Engine RPM: " << m.getData() << std::endl;
}

char* obd::query(char *cmd) {
  std::cout << "Sending CMD: " << cmd << std::endl;


  //obd::buildCommandString(cmd);
}

// Creates the appropriate command string to send to the elm327 interface
void obd::buildCommandString(char *cmd) {

}
