#include <iostream>
#include "src/obd.h"

int main() {
  std::cout << "Reading vehicle OBD data" << std::endl;
  std::cout << "Creating OBD connection in Main ...." << std::endl;
  obd obd;
  obd.connect("/dev/rfcomm0", 115200);
  std::cout << "Done creating OBD object" << std::endl;

  return 0;
}