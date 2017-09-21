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
    return tx_id;
  }

  char *getRaw() {
    return raw;
  }

 private:
  char *raw;
  char *data;
  int priority;
  int addr_mode;
  int rx_id;
  int tx_id;
  int type;
  int seq_index;
  int data_len;
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

//# create the default, empty map
//# for example: self.TX_ID_ENGINE : ECU.ENGINE
//self.ecu_map = {}
//
//# parse the 0100 data into messages
//# NOTE: at this point, their "ecu" property will be UNKNOWN
//messages = self(lines_0100)
//
//# read the messages and assemble the map
//# subsequent runs will now be tagged correctly
//self.populate_ecu_map(messages)
//
//# log out the ecu map
//for tx_id, ecu in self.ecu_map.items():
//    names = [k for k in ECU.__dict__ if ECU.__dict__[k] == ecu ]
//names = ", ".join(names)
//logger.debug("map ECU %d --> %s" % (tx_id, names))
//
//
//def __call__(self, lines):
//"""
//Main function
//accepts a list of raw strings from the car, split by lines
//"""
//
//# ---------------------------- preprocess ----------------------------
//
//# Non-hex (non-OBD) lines shouldn't go through the big parsers,
//# since they are typically messages such as: "NO DATA", "CAN ERROR",
//# "UNABLE TO CONNECT", etc, so sort them into these two lists:
//    obd_lines = []
//non_obd_lines = []
//
//for line in lines:
//
//    line_no_spaces = line.replace(' ', '')
//
//if isHex(line_no_spaces):
//obd_lines.append(line_no_spaces)
//else:
//non_obd_lines.append(line) # pass the original, un-scrubbed line
//
//# ---------------------- handle valid OBD lines ----------------------
//
//# parse each frame (each line)
//frames = []
//for line in obd_lines:
//
//    frame = Frame(line)
//
//# subclass function to parse the lines into Frames
//# drop frames that couldn't be parsed
//if self.parse_frame(frame):
//frames.append(frame)
//
//
//# group frames by transmitting ECU
//# frames_by_ECU[tx_id] = [Frame, Frame]
//frames_by_ECU = {}
//for frame in frames:
//if frame.tx_id not in frames_by_ECU:
//frames_by_ECU[frame.tx_id] = [frame]
//else:
//frames_by_ECU[frame.tx_id].append(frame)
//
//# parse frames into whole messages
//messages = []
//for ecu in frames_by_ECU:
//
//# new message object with a copy of the raw data
//# and frames addressed for this ecu
//    message = Message(frames_by_ECU[ecu])
//
//# subclass function to assemble frames into Messages
//if self.parse_message(message):
//# mark with the appropriate ECU ID
//message.ecu = self.ecu_map.get(ecu, ECU.UNKNOWN)
//messages.append(message)
//
//# ----------- handle invalid lines (probably from the ELM) -----------
//
//for line in non_obd_lines:
//# give each line its own message object
//# messages are ECU.UNKNOWN by default
//    messages.append( Message([ Frame(line) ]) )
//
//return messages
//
//
//    def populate_ecu_map(self, messages):
//"""
//Given a list of messages from different ECUS,
//(in response to the 0100 PID listing command)
//associate each tx_id to an ECU ID constant.
//This is mostly concerned with finding the engine.
//"""
//
//# filter out messages that don't contain any data
//# this will prevent ELM responses from being mapped to ECUs
//messages = [ m for m in messages if m.parsed() ]
//
//# populate the map
//if len(messages) == 0:
//pass
//    elif len(messages) == 1:
//# if there's only one response, mark it as the engine regardless
//self.ecu_map[messages[0].tx_id] = ECU.ENGINE
//        else:
//
//            # the engine is important
//            # if we can't find it, we'll use a fallback
//            found_engine = False
//
//            # if any tx_ids are exact matches to the expected values, record them
//            for m in messages:
//                if m.tx_id is None:
//                    logger.debug("parse_frame failed to extract TX_ID")
//                    continue
//
//                if m.tx_id == self.TX_ID_ENGINE:
//                    self.ecu_map[m.tx_id] = ECU.ENGINE
//                    found_engine = True
//                elif m.tx_id == self.TX_ID_TRANSMISSION:
//                    self.ecu_map[m.tx_id] = ECU.TRANSMISSION
//                # TODO: program more of these when we figure out their constants
//
//            if not found_engine:
//                # last resort solution, choose ECU with the most bits set
//                # (most PIDs supported) to be the engine
//                best = 0
//                tx_id = None
//
//                for message in messages:
//                    bits = bitarray(message.data).num_set()
//
//                    if bits > best:
//                        best = bits
//                        tx_id = message.tx_id
//
//                self.ecu_map[tx_id] = ECU.ENGINE
//
//            # any remaining tx_ids are unknown
//            for m in messages:
//                if m.tx_id not in self.ecu_map:
//                    self.ecu_map[m.tx_id] = ECU.UNKNOWN
//
//
//    def parse_frame(self, frame):
//        """
//            override in subclass for each protocol
//            Function recieves a Frame object preloaded
//            with the raw string line from the car.
//            Function should return a boolean. If fatal errors were
//            found, this function should return False, and the Frame will be dropped.
//        """
//        raise NotImplementedError()
//
//
//    def parse_message(self, message):
//        """
//            override in subclass for each protocol
//            Function recieves a Message object
//            preloaded with a list of Frame objects.
//            Function should return a boolean. If fatal errors were
//            found, this function should return False, and the Message will be dropped.
//        """
//        raise NotImplementedError()
//
#endif //OBD_CPP_PROTOCOL_H
