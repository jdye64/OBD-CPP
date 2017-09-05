//
// Created by Jeremy Dyer on 9/5/17.
//

#ifndef OBD_CPP_ELM327_H
#define OBD_CPP_ELM327_H

#include "OBDStatus.h"
#include "iostream"
#include <boost/bind.hpp>
#include <boost/asio.hpp>

class elm327 {

 public:

  explicit elm327(const char* portStr, int baudRate) {

    std::cout << "Open ELM327 interface connection" << std::endl;

    // Open connection port
    static boost::asio::io_service ios;
    boost::asio::serial_port sp(ios, portStr);

    //Set ASIO options
    std::cout << "Setting boost.asio options on serial connection" << std::endl;
    sp.set_option(boost::asio::serial_port::baud_rate(baudRate));

//    // You can set other options using similar syntax
//    char tmp[64];
//    sp.read_some(boost::asio::buffer(tmp));
//    std::cout << tmp << std::endl;
//    sp.close();
  }

  ~ elm327() {
    //sp.close();
  }

 protected:

  static const char _ELM_PROMPT = '>';



 private:

};

#endif //OBD_CPP_ELM327_H
