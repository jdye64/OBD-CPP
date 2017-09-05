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
      const char* data = "ATZ";
      sp.write_some(boost::asio::buffer(data, strlen(data)));

      std::cout << "Reading the input after ATZ reset" << std::endl;
      char c;
      do {
        sp.read_some(boost::asio::buffer(&c, 1));
        std::cout << "Read data: '" << c << "' from the serial port";
      } while(c != '>');

    } catch (...) {
      std::cout << "Error occured while trying to reset ATZ" << std::endl;
      exit(-1);
    }

    // ATE0 Echo Off
    try {
      const char *atData = "ATE0";
      sp.write_some(boost::asio::buffer(atData, strlen(atData)));
    } catch (...) {
      std::cout << "Error setting ATE0 to Echo OFF" << std::endl;
      exit(-1);
    }

    // ATH1 Headers on
    try {
      const char *athData = "ATH1";
      sp.write_some(boost::asio::buffer(athData, strlen(athData)));
    } catch (...) {
      std::cout << "Error setting ATH1 Header on" << std::endl;
      exit(-1);
    }

    // ATL0 Linefeeds Off
    try {
      const char *atlData = "ATL0";
      sp.write_some(boost::asio::buffer(atlData, strlen(atlData)));
    } catch (...) {
      std::cout << "Error setting ATL0 Linefeeds Off" << std::endl;
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
