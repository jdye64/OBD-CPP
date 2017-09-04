#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

int main() {
  std::cout << "Reading vehicle OBD data" << std::endl;

  static boost::asio::io_service ios;
  boost::asio::serial_port sp(ios, "/dev/rfcomm0");

  //Set ASIO options
  sp.set_option(boost::asio::serial_port::baud_rate(115200));

  // You can set other options using similar syntax
  char tmp[64];
  sp.read_some(boost::asio::buffer(tmp));
  std::cout << tmp << std::endl;
  sp.close();

  return 0;
}