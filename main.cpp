#include <iostream>
#include "src/obd.h"
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include "src/protocols/protocol.h"


int main() {

//  Frame f("48 6B 10 41 0C 08 9F 59");

  std::cout << "Reading vehicle OBD data" << std::endl;
  std::cout << "Creating OBD connection in Main ...." << std::endl;
  obd obd;
  obd.connect("/dev/rfcomm0", 38400);
  std::cout << "Done creating OBD object" << std::endl;

  return 0;
}