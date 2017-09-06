//
// Created by Jeremy Dyer on 9/5/17.
//

#ifndef OBD_CPP_ELM327_H
#define OBD_CPP_ELM327_H

#include "OBDStatus.h"
#include "iostream"
#include <sstream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

class elm327 {

 public:

  elm327(const char* portStr, int baudRate);

  ~ elm327() {
    std::cout << "Closing ELM327 Interface" << std::endl;
    _serialPort.close();
  }

 protected:

  static const char _ELM_PROMPT = '>';

  std::string _send(const char* cmd, int msDelay);

  std::string _write(const char* cmd, intmsDelay);

  std::string _read();

 private:

  boost::asio::serial_port _serialPort;
  int _defaultReadBytes = 64;

};

#endif //OBD_CPP_ELM327_H
