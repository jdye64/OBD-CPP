//
// Created by Jeremy Dyer on 9/5/17.
//

#ifndef OBD_CPP_OBDCOMMAND_H
#define OBD_CPP_OBDCOMMAND_H

#include "string"

class OBDCommand {

 public:

  OBDCommand(std::string name, std::string desc, std::string cmd,
             int bytes, std::string decoder, std::string ecu, bool fast);

 protected:

 private:
  std::string _name;
  std::string _desc;
  std::string _cmd;
  int _bytes;
  std::string _decoder;
  std::string _ecu;
  bool _fast;

};

#endif //OBD_CPP_OBDCOMMAND_H
