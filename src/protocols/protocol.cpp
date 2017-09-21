#include "protocol.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <sstream>
#include <string.h>

Frame::Frame(std::string raw) {
  std::cout << "Creating Frame from RAW: " << raw << std::endl;
  std::cout << "RAW Length: " << raw.size() << std::endl;


  std::string::size_type n;
  n = raw.find(" ");
  while (n != std::string::npos) {
    raw.erase(n, strlen(" "));
    n = raw.find(" ");
  }

  std::cout << "RAW Length: " << raw.size() << std::endl;
  std::vector<char> bytes;

  for (unsigned int i = 0; i < raw.length(); i += 2) {
    std::string byteString = raw.substr(i, 2);
    char byte = (char) strtol(byteString.c_str(), NULL, 16);
    std::cout << "Byte: '" << byte << "'" << std::endl;
    bytes.push_back(byte);
  }

  std::cout << "Number of Bytes: " << bytes.size() << std::endl;

  // Use the bytes to populate the Frame properties
  _priority = bytes[0];
  _rx_id = bytes[1];
  _tx_id = bytes[2];

  unsigned int first;
  unsigned int second;
  std::stringstream ss;
  ss << bytes[5];
  ss >> std::hex >> first;
  ss << bytes[6];
  ss >> std::hex >> second;
  std::cout << (first + second) << std::endl;
  std::cout << ((first + second) / 4) << " RPM" << std::endl;

}

Message::Message() {
  std::cout << "Nothing will happen here" << std::endl;
}

Message::Message(std::vector<std::string> lines) {
  // Parse the lines into Frame objects.
  for(std::string str : lines) {
    Frame f(str);
    _frames.push_back(f);
  }
}

Message::Message(std::vector<Frame> frames) {
  std::cout << "ERROR: Not currently implemented!" << std::endl;
}