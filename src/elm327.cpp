//
// Created by Jeremy Dyer on 9/5/17.
//

#include "elm327.h"

elm327::elm327(const char* portStr, int baudRate) {

  std::cout << "Open ELM327 interface connection" << std::endl;

  // Open connection port
  std::cout << "Opening serial port now" << std::endl;
  static boost::asio::io_service ios;
  _serialPort = boost::asio::serial_port(ios, portStr);
  std::cout << "Is /dev/rfcomm0 open?: " << sp.is_open() << std::endl;

  //Set ASIO options
  std::cout << "Setting boost.asio options on serial connection" << std::endl;
  sp.set_option(boost::asio::serial_port::baud_rate(baudRate));

  // ATZ (reset)
  try {
    const char* data = "ATZ";
    sp.write_some(boost::asio::buffer(data, strlen(data)));

    std::cout << "Reading the input after ATZ reset" << std::endl;
    char c;
    do {
      sp.read_some(boost::asio::buffer(&c, 1));
      std::cout << "Read data: '" << c << "' from the serial port" << std::endl;
    } while(c != '>');

  } catch (...) {
    std::cout << "Error occured while trying to reset ATZ" << std::endl;
    exit(-1);
  }

  // ATE0 Echo Off
  try {
    const char *atData = "ATE0";
    sp.write_some(boost::asio::buffer(atData, strlen(atData)));

    std::cout << "Reading the input after ATE0 Echo Off" << std::endl;
    char c;
    do {
      sp.read_some(boost::asio::buffer(&c, 1));
      std::cout << "Read data: '" << c << "' from the serial port" << std::endl;
    } while(c != '>');

  } catch (...) {
    std::cout << "Error setting ATE0 to Echo OFF" << std::endl;
    exit(-1);
  }

  // ATH1 Headers on
  try {
    const char *athData = "ATH1";
    sp.write_some(boost::asio::buffer(athData, strlen(athData)));

    std::cout << "Reading the input after ATH1 Headers On" << std::endl;
    char c;
    do {
      sp.read_some(boost::asio::buffer(&c, 1));
      std::cout << "Read data: '" << c << "' from the serial port" << std::endl;
    } while(c != '>');

  } catch (...) {
    std::cout << "Error setting ATH1 Header on" << std::endl;
    exit(-1);
  }

  // ATL0 Linefeeds Off
  try {
    const char *atlData = "ATL0";
    sp.write_some(boost::asio::buffer(atlData, strlen(atlData)));

    std::cout << "Reading the input after ATL0 Linefeeds Off" << std::endl;
    char c;
    do {
      sp.read_some(boost::asio::buffer(&c, 1));
      std::cout << "Read data: '" << c << "' from the serial port" << std::endl;
    } while(c != '>');

  } catch (...) {
    std::cout << "Error setting ATL0 Linefeeds Off" << std::endl;
    exit(-1);
  }

  std::cout << std::endl << "Finished connecting to ELM327 Interface!!!" << std::endl;
}

std::string elm327::_send(const char* cmd, int msDelay) {

}

std::string elm327::_write(const char* cmd, int msDelay) {

}

/**
 * "low-level" read function accumulates characters until the prompt character is seen
 *
 * @return
 *  list of [/r/n] delimited strings
 */
std::string elm327::_read() {

  if (!_serialPort.is_open()) {
    std::cout << "cannot perform _read() operation. Serial port is not open/connected" << std::endl;
    return std::string("");
  }

  std::stringstream buffer;
  char *data;

  while (true) {
    // retrieve as much data as possible.
    _serialPort.read_some(boost::asio::buffer(&data, _defaultReadBytes));
    if (!data) {
      std::cout << "Failed to read data from serial port" << std::endl;
      break;
    }

    buffer << data;

    // End on a chevron (ELM prompt character)
    if (strstr(data, _ELM_PROMPT) != NULL) {
      std::cout << "ELM Prompt Chevron found in data C String" << std::endl;
      break;
    }

  }

  // Clean out an null characters
  //buffer = re.sub(b"\x00", b"", buffer)

  // Remove the prompt character
  //if buffer.endswith(self.ELM_PROMPT):
  //  buffer = buffer[:-1]

  //# splits into lines while removing empty lines and trailing spaces
  //lines = [ s.strip() for s in re.split("[\r\n]", string) if bool(s) ]
  //
  //return lines

  std::string str = ss.str();
  std::cout << "_read() -> '" << str.c_str() << "'" << std::endl;
  return str;

}