#include "protocol.h"

Frame::Frame(std::string raw) {
  std::cout << "Creating Frame from RAW: " << raw << std::endl;
  std::cout << "RAW Length: " << raw.size() << std::endl;

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