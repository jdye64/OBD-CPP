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
    std::cout << "Opening serial port now" << std::endl;
    static boost::asio::io_service ios;
    boost::asio::serial_port sp(ios, portStr);
    std::cout << "Is /dev/rfcomm0 open?: " << sp.is_open() << std::endl;


    //Set ASIO options
    std::cout << "Setting boost.asio options on serial connection" << std::endl;
    sp.set_option(boost::asio::serial_port::baud_rate(baudRate));

//    char c;
//
//    boost::asio::read(sp, boost::asio::buffer(&c,1));
//    sp.close();
//    std::cout << "Read character: '" << c << "' from the serial port" << std::endl;

    // ATZ (reset)
    try {
      sp.write_some("ATZ");
    } catch (...) {
      std::cout << "Error occured while trying to reset ATZ" << std::endl;
      exit(-1);
    }

    // ATE0 Echo Off
    try {
      sp.write_some("ATE0");
    } catch (...) {
      std::cout << "Error setting ATE0 to Echo OFF" << std::endl;
      exit(-1);
    }

    std::cout << "Finished connecting to ELM327 Interface!!!" << std::endl;
  }

  ~ elm327() {
    //sp.close();
  }

 protected:

  static const char _ELM_PROMPT = '>';



 private:

};

#endif //OBD_CPP_ELM327_H
