#include "protocol.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <sstream>
#include <string.h>

Frame::Frame(std::string raw) {
  std::cout << "Creating Frame from RAW: " << raw << std::endl;
  _rawFrameData = raw;

  // Remove all of the spaces and invalid characters.
  std::string::size_type n;
  n = raw.find(" ");
  while (n != std::string::npos) {
    raw.erase(n, strlen(" "));
    n = raw.find(" ");
  }

  // Drop the frame if the size of the byte array is odd since all should be even.
  if (raw.size() & 1) {
    std::cout << "WARN: Frame length is odd. Dropping frame." << std::endl;
    return;
  }

  std::vector<std::string> bytes;

  for (unsigned int i = 0; i < raw.length(); i += 2) {
    std::string byteString = raw.substr(i, 2);
    bytes.push_back(byteString);
  }

  if(bytes.size() < 6) {
    std::cout << "Dropped frame for being too short" << std::endl;
    return;
  }

  if (bytes.size() > 11) {
    std::cout << "Dropped frame for being too long" << std::endl;
    return;
  }

  // Ex.
  // [Header] [       Frame        ]
  // 48 6B 10  41 00 BE 7F B8 13 ck
  // ck = checksum byte

  // Exclude header and trailing checksum (handled by ELM adapter)
  int i = 1;
  for (std::string b : bytes) {
    if (i > 3 && i != bytes.size()) {
      _frameBytes.push_back(b);
    } else if (i <= 3) {
      _headerBytes.push_back(b);
    } else {
      _checksumByte = b;
    }
    ++i;
  }

  std::stringstream ss;
  int val;
  ss << _headerBytes[0];
  ss >> std::hex >> val;
  _priority = val;
  ss << _headerBytes[1];
  ss >> std::hex >> val;
  _rx_id = val;
  ss << _headerBytes[2];
  ss >> std::hex >> val;
  _tx_id = val;

//  int rpmTotal;
//
//  ss << byteStrings[5] << byteStrings[6];
//  ss >> std::hex >> rpmTotal;
//  std::cout << "RPM Total: " << rpmTotal << std::endl;
//  std::cout << "RPM: " << (rpmTotal / 4) << std::endl;

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