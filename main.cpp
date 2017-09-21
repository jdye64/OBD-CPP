#include <iostream>
#include "src/obd.h"
#include <vector>


int main() {

  std::cout << "Reading vehicle OBD data" << std::endl;
  std::cout << "Creating OBD connection in Main ...." << std::endl;
  obd obd;
  obd.connect("/dev/rfcomm0", 38400);
  std::cout << "Done creating OBD object" << std::endl;

  return 0;
}