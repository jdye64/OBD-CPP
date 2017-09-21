#include <iostream>
#include "src/obd.h"
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>


int main() {

//  std::stringstream ss;
//  unsigned int rpmTotal;
//  ss << bytes[5] << bytes[6];
//  ss >> std::hex >> rpmTotal;
//  std::cout << "RPM Total: " << rpmTotal << std::endl;
//  std::cout << "RPM: " << (rpmTotal / 4) << std::endl;

  std::stringstream ss;
  unsigned int rpm;
  ss << "089F";
  ss >> std::hex >> rpm;
  std::cout << "RPM Testing: " << (rpm / 4) << std::endl;

//  std::cout << "Reading vehicle OBD data" << std::endl;
//  std::cout << "Creating OBD connection in Main ...." << std::endl;
//  obd obd;
//  obd.connect("/dev/rfcomm0", 38400);
//  std::cout << "Done creating OBD object" << std::endl;

  return 0;
}