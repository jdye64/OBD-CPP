//
// Created by Jeremy Dyer on 9/5/17.
//

#include "commands.h"

//# mode 2 is the same as mode 1, but returns values from when the DTC occured
//__mode2__ = []
//for c in __mode1__:
//    c = c.clone()
//    c.command = b"02" + c.command[2:] # change the mode: 0100 ---> 0200
//    c.name = "DTC_" + c.name
//    c.desc = "DTC " + c.desc
//    if c.decode == pid:
//        c.decode = drop # Never send mode 02 pid requests (use mode 01 instead)
//    __mode2__.append(c)

//class Commands():
//    def __getitem__(self, key):
//        """
//            commands can be accessed by name, or by mode/pid
//
//            obd.commands.RPM
//            obd.commands["RPM"]
//            obd.commands[1][12] # mode 1, PID 12 (RPM)
//        """
//
//        if isinstance(key, int):
//            return self.modes[key]
//        elif isinstance(key, str) or isinstance(key, unicode):
//            return self.__dict__[key]
//        else:
//            logger.warning("OBD commands can only be retrieved by PID value or dict name")
//
//
//    def __len__(self):
//        """ returns the number of commands supported by python-OBD """
//        return sum([len(mode) for mode in self.modes])
//
//
//    def __contains__(self, name):
//        """ calls has_name(s) """
//        return self.has_name(name)
//
//
//    def base_commands(self):
//        """
//            returns the list of commands that should always be
//            supported by the ELM327
//        """
//        return [
//            self.PIDS_A,
//            self.MIDS_A,
//            self.GET_DTC,
//            self.CLEAR_DTC,
//            self.GET_CURRENT_DTC,
//            self.ELM_VERSION,
//            self.ELM_VOLTAGE,
//        ]
//
//
//    def pid_getters(self):
//        """ returns a list of PID GET commands """
//        getters = []
//        for mode in self.modes:
//            getters += [ cmd for cmd in mode if (cmd and cmd.decode == pid) ]
//        return getters
//
//
//    def has_command(self, c):
//        """ checks for existance of a command by OBDCommand object """
//        return c in self.__dict__.values()
//
//
//    def has_name(self, name):
//        """ checks for existance of a command by name """
//        # isupper() rejects all the normal properties
//        return name.isupper() and name in self.__dict__
//
//
//    def has_pid(self, mode, pid):
//        """ checks for existance of a command by int mode and int pid """
//        if (mode < 0) or (pid < 0):
//            return False
//        if mode >= len(self.modes):
//            return False
//        if pid >= len(self.modes[mode]):
//            return False
//
//        # make sure that the command isn't reserved
//        return (self.modes[mode][pid] is not None)
