#include <iostream>
#include "src/obd.h"
#include <sstream>
#include <vector>


int main() {

  char* bytes = "486B10410C088546";
  std::cout << "Bytes Length: " + strlen(bytes) << std::endl;

//  obd obd;
//  obd.connect("/dev/rfcomm0", 38400);
  return 0;
}