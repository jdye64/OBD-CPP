#include "elm327.h"
#include <stdio.h>

elm327::elm327(const char* portStr, int baudRate) : _serialPort(ios) {

  std::cout << "Open ELM327 interface connection" << std::endl;

  // Open connection port
  std::cout << "Opening serial port now" << std::endl;

  boost::system::error_code ec;
  _serialPort.open(portStr, ec);
  if (ec) {
    std::cout << "error : _serialPort->open() failed...com_port_name="
              << portStr << ", e=" << ec.message().c_str() << std::endl;
  }

  //_serialPort = boost::asio::serial_port(ios, portStr);
  std::cout << "Is /dev/rfcomm0 open?: " << _serialPort.is_open() << std::endl;

  //Set ASIO options
  std::cout << "Setting boost.asio options on serial connection" << std::endl;
  _serialPort.set_option(boost::asio::serial_port::baud_rate(baudRate));
  _serialPort.set_option(boost::asio::serial_port_base::character_size(8));
  _serialPort.set_option(boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));
  _serialPort.set_option(boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none));
  _serialPort.set_option(boost::asio::serial_port_base::flow_control(boost::asio::serial_port_base::flow_control::none));

  std::string resp;
  // ATZ (reset)
  try {
    resp = _send("ATZ", 1000);
  } catch (...) {
    std::cout << "Error occured while trying to reset ATZ" << std::endl;
    exit(-1);
  }

  // ATE0 Echo Off
  try {
    resp = _send("ATE0", 0);
  } catch (...) {
    std::cout << "Error setting ATE0 to Echo OFF" << std::endl;
    exit(-1);
  }

  // ATH1 Headers on
  try {
    resp = _send("ATH1", 0);
  } catch (...) {
    std::cout << "Error setting ATH1 Header on" << std::endl;
    exit(-1);
  }

  // ATL0 Linefeeds Off
  try {
    resp = _send("ATL0", 0);
  } catch (...) {
    std::cout << "Error setting ATL0 Linefeeds Off" << std::endl;
    exit(-1);
  }

  std::cout << std::endl << "Successfully communicated with the ELM but not yet the Car" << std::endl;
  _obdStatus = ELM_CONNECTED;

  // Right now just manually set the protocol that will be used for this implementation
//  r = self.__send(b"ATTP" + protocol.encode())
//  r0100 = self.__send(b"0100")
//
//  if not self.__has_message(r0100, "UNABLE TO CONNECT"):
//# success, found the protocol
//  self.__protocol = self._SUPPORTED_PROTOCOLS[protocol](r0100)
//  return True
//
//
//  std::cout << std::endl << "Finished connecting to ELM327 Interface!!!" << std::endl;
}

/**
 * Sends the command string and parse the response lines with the protocol object.
 * An empty command string will re-trigger the previous command.
 *
 * @param cmd
 * @return
 */
std::string elm327::_send_and_parse(char* cmd) {

  if (_obdStatus == NOT_CONNECTED) {
    std::cout << "cannot _send_and_parse() when unconnected" << std::endl;
    return std::string("");
  }

  std::string lines = _send(cmd, 0);
  return lines;
//  messages = self.__protocol(lines)
//  return messages
}

std::string elm327::_send(char* cmd, int msDelay) {

  std::cout << "Entering _send()" << std::endl;
  _write(cmd);
  if (msDelay > 0) {
    std::cout << "Sleeping for " << msDelay << " milliseconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(msDelay));
  }
  std::cout << "Exiting _send(), but before _read() is called" << std::endl;
  return _read();

}

void elm327::_write(char* cmd) {

  std::cout << "Entering _write()" << std::endl;
  std::string tData(cmd);

  if (_serialPort.is_open()) {
    std::cout << "CMD current value is: " << tData << std::endl;
    //char *updatedCommand = strcat(cmd, "\r\n");
    tData.append("\r\n");
    std::cout << "Writing updated CMD: " << tData << std::endl;
    _serialPort.write_some(boost::asio::buffer(tData, tData.length()));
  } else {
    std::cout << "Cannot perform _write() operation when the vehicle is not connected" << std::endl;
  }

}


/**
 * "low-level" read function accumulates characters until the prompt character is seen
 *
 * @return
 *  list of [/r/n] delimited strings
 */
std::string elm327::_read() {

  std::cout << "Entering _read()" << std::endl;

  if (!_serialPort.is_open()) {
    std::cout << "cannot perform _read() operation. Serial port is not open/connected" << std::endl;
    return std::string("");
  }

  std::string buffer;
  buffer.clear();
  char data[_defaultReadBytes];
  int numBytes = 0;

  while (true) {
    // retrieve as much data as possible.
    size_t bytesWritten = _serialPort.read_some(boost::asio::buffer(data, _defaultReadBytes));
    if (bytesWritten <= 0) {
      std::cout << "Failed to read data from serial port" << std::endl;
      break;
    }
    numBytes += bytesWritten;

    printf ("[%s] is a string %d chars long\n", buffer.c_str(), buffer.length());
    std::cout << "Appending data: '" << data << "' to the buffer with size: " << strlen(data) << std::endl;
    buffer += data;
    std::cout << "Buffer after appending: " << buffer.c_str() << std::endl;

    // End on a chevron (ELM prompt character)
    if (strstr(data, &_ELM_PROMPT) != NULL) {
      std::cout << "ELM Prompt Chevron found in data C String" << std::endl;
      break;
    }

    // Clear out the char array for the next pass
    memset(data, 0, strlen(data));
  }

  // Remove the ELM prompt
  elm327::removeAllOccurances(buffer, ">");

  std::vector<std::string> lines = elm327::splitMessageToLines(buffer);
  std::cout << lines.size() << " lines split from the entire message received" << std::endl;

  std::cout << numBytes << " were read from the input" << std::endl;
  std::cout << "Output buffer std::string" << std::endl;
  std::cout << "_read() -> '" << buffer.c_str() << "'" << std::endl;
  return buffer.c_str();

}


void elm327::removeAllOccurances(std::string &s, char *toRemove) {
  std::string::size_type n;
  n = s.find(toRemove);
  while (n != std::string::npos) {
    s.erase(n, strlen(toRemove));
    n = s.find(toRemove);
  }
}

std::vector<std::string> elm327::splitMessageToLines(std::string &s) {
  std::vector<std::string> lines;
  int lastFindIndex = 0;
  std::string::size_type n;
  n = s.find("\r\n");
  while (n != std::string::npos) {
    if (n > 0) {
      std::string f = s.substr(lastFindIndex, n - lastFindIndex);
      lines.push_back(f);
      lastFindIndex = n + 2;
    } else {
      //This is the beginning of the string so just updated the last fine index.
      lastFindIndex = 2;  // length of \r\n
    }
    n = s.find("\r\n", lastFindIndex);
  }

  //Add the last element to the vector
  lines.push_back(s.substr(lastFindIndex, s.length() - lastFindIndex));

  return lines;
}