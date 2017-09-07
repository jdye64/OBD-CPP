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
#include <chrono>
#include <thread>

static boost::asio::io_service ios;
static const char _ELM_PROMPT = '>';

class elm327 {

 public:

  elm327(const char* portStr, int baudRate);

  ~ elm327() {
    std::cout << "Closing ELM327 Interface" << std::endl;
    _serialPort.close();
  }

 protected:

  std::string _send_and_parse(char* cmd);

  std::string _send(char* cmd, int msDelay);

  void _write(char* cmd);

  std::string _read();

 private:

  boost::asio::serial_port _serialPort;
  int _defaultReadBytes = 64;
  char *_obdStatus = NOT_CONNECTED;

};

#endif //OBD_CPP_ELM327_H
