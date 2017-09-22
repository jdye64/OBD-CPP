#ifndef OBD_CPP_PROTOCOL_H
#define OBD_CPP_PROTOCOL_H

#include "iostream"
#include <vector>


class ECU {
 public:
  // Constant flags used for marking and filtering messages
  char ALL        = 0xFF;  // used by OBDCommands to accept messages from any ECU
  char ALL_KNOWN  = 0xFE;  // used to ignore unknown ECUs, since this lib probably can't handle them

  // Each ECU gets its own bit for ease of making OR filters
  char UNKNOWN    = 0x01; // unknowns get their own bit, since they need to be accepted by the ALL filter
  char ENGINE     = 0x02;
  char TRANSMISSION = 0x04;

  ECU();

  ~ ECU(){

  }
};

class Frame {
 public:

  Frame(std::string);

  int getTXID() {
    return _tx_id;
  }

  char *getRaw() {
    return _rawBytes;
  }

 private:

  std::vector<std::string> _headerBytes;
  std::vector<std::string> _frameBytes;
  std::string _checksumByte;

  std::string _rawFrameData;
  char* _rawBytes;
  int _priority;
  int _addr_mode;
  int _rx_id;
  int _tx_id;
  int _type;
  int _seq_index;
  int _data_len;
};

// Represents a fully parsed OBD message of one or more Frames (lines)
class Message {

 public:
  Message();
  Message(std::vector<std::string> lines);
  Message(std::vector<Frame> frames);

  int tx_id() {
    if (!_frames.empty()) {
      return _frames[0].getTXID();
    } else {
      return -1;
    }
  }

  char *hex() {
    return "HEX String should be placed here";
  }

  char *raw() {
    return _frames[0].getRaw();
  }

  char* getData() {
    return data;
  }

 private:
  std::vector<Frame> _frames;
  char *ecu;
  char *data;
};

/**
 * Protocol objects are factories for Frame and Message objects. The are largely stateless, with the
 * exception of an ECU tagging system, which is initialized by passing the response to an "0100" command.
 *
 * Protocols are called with a list of string responses, and return a list of Messages.
 */
class protocol {

 public:

  char *ELM_NAME = "";   // The ELM's name for this protocol (ie, "SAE J1939 (CAN 29/250)")
  char *ELM_ID   = "";   // the ELM's ID for this protocol (ie "A")

  int TX_ID_ENGINE = 0;
  int TX_ID_TRANSMISSION = 0;

  protocol() {

  }

  ~ protocol() {

  }

  bool parse_frame(Frame frame);

  bool parse_message(Message message);

 protected:

 private:

};

#endif //OBD_CPP_PROTOCOL_H
