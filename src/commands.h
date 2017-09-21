//
// Created by Jeremy Dyer on 9/5/17.
//

#ifndef OBD_CPP_COMMANDS_H
#define OBD_CPP_COMMANDS_H

#include "OBDCommand.h"
#include "vector"

class commands {

 public:

  commands() {
    // Builds the vector of Mode1 OBDCommands
    _mode1.push_back(OBDCommand("PIDS_A"                     , "Supported PIDs [01-20]"                  , "0100", 6, "pid",                   "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("STATUS"                     , "Status since DTCs cleared"               , "0101", 6, "status",                "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FREEZE_DTC"                 , "DTC that triggered the freeze frame"     , "0102", 4, "single_dtc",            "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_STATUS"                , "Fuel System Status"                      , "0103", 4, "fuel_status",           "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("ENGINE_LOAD"                , "Calculated Engine Load"                  , "0104", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("COOLANT_TEMP"               , "Engine Coolant Temperature"              , "0105", 3, "temp",                  "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("SHORT_FUEL_TRIM_1"          , "Short Term Fuel Trim - Bank 1"           , "0106", 3, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("LONG_FUEL_TRIM_1"           , "Long Term Fuel Trim - Bank 1"            , "0107", 3, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("SHORT_FUEL_TRIM_2"          , "Short Term Fuel Trim - Bank 2"           , "0108", 3, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("LONG_FUEL_TRIM_2"           , "Long Term Fuel Trim - Bank 2"            , "0109", 3, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_PRESSURE"              , "Fuel Pressure"                           , "010A", 3, "fuel_pressure",         "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("INTAKE_PRESSURE"            , "Intake Manifold Pressure"                , "010B", 3, "pressure",              "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("RPM"                        , "Engine RPM"                              , "010C", 4, "uas(0x07)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("SPEED"                      , "Vehicle Speed"                           , "010D", 3, "uas(0x09)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("TIMING_ADVANCE"             , "Timing Advance"                          , "010E", 3, "timing_advance",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("INTAKE_TEMP"                , "Intake Air Temp"                         , "010F", 3, "temp",                  "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("MAF"                        , "Air Flow Rate (MAF)"                     , "0110", 4, "uas(0x27)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("THROTTLE_POS"               , "Throttle Position"                       , "0111", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("AIR_STATUS"                 , "Secondary Air Status"                    , "0112", 3, "air_status",            "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_SENSORS"                 , "O2 Sensors Present"                      , "0113", 3, "o2_sensors",            "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_B1S1"                    , "O2: Bank 1 - Sensor 1 Voltage"           , "0114", 4, "sensor_voltage",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_B1S2"                    , "O2: Bank 1 - Sensor 2 Voltage"           , "0115", 4, "sensor_voltage",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_B1S3"                    , "O2: Bank 1 - Sensor 3 Voltage"           , "0116", 4, "sensor_voltage",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_B1S4"                    , "O2: Bank 1 - Sensor 4 Voltage"           , "0117", 4, "sensor_voltage",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_B2S1"                    , "O2: Bank 2 - Sensor 1 Voltage"           , "0118", 4, "sensor_voltage",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_B2S2"                    , "O2: Bank 2 - Sensor 2 Voltage"           , "0119", 4, "sensor_voltage",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_B2S3"                    , "O2: Bank 2 - Sensor 3 Voltage"           , "011A", 4, "sensor_voltage",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_B2S4"                    , "O2: Bank 2 - Sensor 4 Voltage"           , "011B", 4, "sensor_voltage",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("OBD_COMPLIANCE"             , "OBD Standards Compliance"                , "011C", 3, "obd_compliance",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_SENSORS_ALT"             , "O2 Sensors Present (alternate)"          , "011D", 3, "o2_sensors_alt",        "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("AUX_INPUT_STATUS"           , "Auxiliary input status (power take off)" , "011E", 3, "aux_input_status",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("RUN_TIME"                   , "Engine Run Time"                         , "011F", 4, "uas(0x12)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("PIDS_B"                     , "Supported PIDs [21-40]"                  , "0120", 6, "pid",                   "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("DISTANCE_W_MIL"             , "Distance Traveled with MIL on"           , "0121", 4, "uas(0x25)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_RAIL_PRESSURE_VAC"     , "Fuel Rail Pressure (relative to vacuum)" , "0122", 4, "uas(0x19)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_RAIL_PRESSURE_DIRECT"  , "Fuel Rail Pressure (direct inject)"      , "0123", 4, "uas(0x1B)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S1_WR_VOLTAGE"           , "02 Sensor 1 WR Lambda Voltage"           , "0124", 6, "sensor_voltage_big",    "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S2_WR_VOLTAGE"           , "02 Sensor 2 WR Lambda Voltage"           , "0125", 6, "sensor_voltage_big",    "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S3_WR_VOLTAGE"           , "02 Sensor 3 WR Lambda Voltage"           , "0126", 6, "sensor_voltage_big",    "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S4_WR_VOLTAGE"           , "02 Sensor 4 WR Lambda Voltage"           , "0127", 6, "sensor_voltage_big",    "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S5_WR_VOLTAGE"           , "02 Sensor 5 WR Lambda Voltage"           , "0128", 6, "sensor_voltage_big",    "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S6_WR_VOLTAGE"           , "02 Sensor 6 WR Lambda Voltage"           , "0129", 6, "sensor_voltage_big",    "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S7_WR_VOLTAGE"           , "02 Sensor 7 WR Lambda Voltage"           , "012A", 6, "sensor_voltage_big",    "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S8_WR_VOLTAGE"           , "02 Sensor 8 WR Lambda Voltage"           , "012B", 6, "sensor_voltage_big",    "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("COMMANDED_EGR"              , "Commanded EGR"                           , "012C", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("EGR_ERROR"                  , "EGR Error"                               , "012D", 3, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("EVAPORATIVE_PURGE"          , "Commanded Evaporative Purge"             , "012E", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_LEVEL"                 , "Fuel Level Input"                        , "012F", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("WARMUPS_SINCE_DTC_CLEAR"    , "Number of warm-ups since codes cleared"  , "0130", 3, "uas(0x01)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("DISTANCE_SINCE_DTC_CLEAR"   , "Distance traveled since codes cleared"   , "0131", 4, "uas(0x25)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("EVAP_VAPOR_PRESSURE"        , "Evaporative system vapor pressure"       , "0132", 4, "evap_pressure",         "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("BAROMETRIC_PRESSURE"        , "Barometric Pressure"                     , "0133", 3, "pressure",              "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S1_WR_CURRENT"           , "02 Sensor 1 WR Lambda Current"           , "0134", 6, "current_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S2_WR_CURRENT"           , "02 Sensor 2 WR Lambda Current"           , "0135", 6, "current_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S3_WR_CURRENT"           , "02 Sensor 3 WR Lambda Current"           , "0136", 6, "current_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S4_WR_CURRENT"           , "02 Sensor 4 WR Lambda Current"           , "0137", 6, "current_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S5_WR_CURRENT"           , "02 Sensor 5 WR Lambda Current"           , "0138", 6, "current_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S6_WR_CURRENT"           , "02 Sensor 6 WR Lambda Current"           , "0139", 6, "current_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S7_WR_CURRENT"           , "02 Sensor 7 WR Lambda Current"           , "013A", 6, "current_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("O2_S8_WR_CURRENT"           , "02 Sensor 8 WR Lambda Current"           , "013B", 6, "current_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("CATALYST_TEMP_B1S1"         , "Catalyst Temperature: Bank 1 - Sensor 1" , "013C", 4, "uas(0x16)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("CATALYST_TEMP_B2S1"         , "Catalyst Temperature: Bank 2 - Sensor 1" , "013D", 4, "uas(0x16)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("CATALYST_TEMP_B1S2"         , "Catalyst Temperature: Bank 1 - Sensor 2" , "013E", 4, "uas(0x16)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("CATALYST_TEMP_B2S2"         , "Catalyst Temperature: Bank 2 - Sensor 2" , "013F", 4, "uas(0x16)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("PIDS_C"                     , "Supported PIDs [41-60]"                  , "0140", 6, "pid",                   "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("STATUS_DRIVE_CYCLE"         , "Monitor status this drive cycle"         , "0141", 6, "status",                "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("CONTROL_MODULE_VOLTAGE"     , "Control module voltage"                  , "0142", 4, "uas(0x0B)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("ABSOLUTE_LOAD"              , "Absolute load value"                     , "0143", 4, "absolute_load",         "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("COMMANDED_EQUIV_RATIO"      , "Commanded equivalence ratio"             , "0144", 4, "uas(0x1E)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("RELATIVE_THROTTLE_POS"      , "Relative throttle position"              , "0145", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("AMBIANT_AIR_TEMP"           , "Ambient air temperature"                 , "0146", 3, "temp",                  "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("THROTTLE_POS_B"             , "Absolute throttle position B"            , "0147", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("THROTTLE_POS_C"             , "Absolute throttle position C"            , "0148", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("ACCELERATOR_POS_D"          , "Accelerator pedal position D"            , "0149", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("ACCELERATOR_POS_E"          , "Accelerator pedal position E"            , "014A", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("ACCELERATOR_POS_F"          , "Accelerator pedal position F"            , "014B", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("THROTTLE_ACTUATOR"          , "Commanded throttle actuator"             , "014C", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("RUN_TIME_MIL"               , "Time run with MIL on"                    , "014D", 4, "uas(0x34)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("TIME_SINCE_DTC_CLEARED"     , "Time since trouble codes cleared"        , "014E", 4, "uas(0x34)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("MAX_VALUES"                 , "Various Max values"                      , "014F", 6, "drop",                  "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("MAX_MAF"                    , "Maximum value for mass air flow sensor"  , "0150", 6, "max_maf",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_TYPE"                  , "Fuel Type"                               , "0151", 3, "fuel_type",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("ETHANOL_PERCENT"            , "Ethanol Fuel Percent"                    , "0152", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("EVAP_VAPOR_PRESSURE_ABS"    , "Absolute Evap system Vapor Pressure"     , "0153", 4, "abs_evap_pressure",     "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("EVAP_VAPOR_PRESSURE_ALT"    , "Evap system vapor pressure"              , "0154", 4, "evap_pressure_alt",     "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("SHORT_O2_TRIM_B1"           , "Short term secondary O2 trim - Bank 1"   , "0155", 4, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("LONG_O2_TRIM_B1"            , "Long term secondary O2 trim - Bank 1"    , "0156", 4, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("SHORT_O2_TRIM_B2"           , "Short term secondary O2 trim - Bank 2"   , "0157", 4, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("LONG_O2_TRIM_B2"            , "Long term secondary O2 trim - Bank 2"    , "0158", 4, "percent_centered",      "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_RAIL_PRESSURE_ABS"     , "Fuel rail pressure (absolute)"           , "0159", 4, "uas(0x1B)",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("RELATIVE_ACCEL_POS"         , "Relative accelerator pedal position"     , "015A", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("HYBRID_BATTERY_REMAINING"   , "Hybrid battery pack remaining life"      , "015B", 3, "percent",               "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("OIL_TEMP"                   , "Engine oil temperature"                  , "015C", 3, "temp",                  "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_INJECT_TIMING"         , "Fuel injection timing"                   , "015D", 4, "inject_timing",         "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("FUEL_RATE"                  , "Engine fuel rate"                        , "015E", 4, "fuel_rate",             "ECU.ENGINE", true));
    _mode1.push_back(OBDCommand("EMISSION_REQ"               , "Designed emission requirements"          , "015F", 3, "drop",                  "ECU.ENGINE", true));

    _mode3.push_back(OBDCommand("GET_DTC"                    , "Get DTCs"                                , "03",   0, "dtc",                   "ECU.ALL",     false));

    _mode4.push_back(OBDCommand("CLEAR_DTC"                  , "Clear DTCs and Freeze data"              , "04",   0, "drop",                  "ECU.ALL",     false));

    _mode6.push_back(OBDCommand("MIDS_A"                      , "Supported MIDs [01-20]"                         , "0600",   0, "pid",                   "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B1S1"             , "O2 Sensor Monitor Bank 1 - Sensor 1"            , "0601",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B1S2"             , "O2 Sensor Monitor Bank 1 - Sensor 2"            , "0602",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B1S3"             , "O2 Sensor Monitor Bank 1 - Sensor 3"            , "0603",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B1S4"             , "O2 Sensor Monitor Bank 1 - Sensor 4"            , "0604",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B2S1"             , "O2 Sensor Monitor Bank 2 - Sensor 1"            , "0605",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B2S2"             , "O2 Sensor Monitor Bank 2 - Sensor 2"            , "0606",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B2S3"             , "O2 Sensor Monitor Bank 2 - Sensor 3"            , "0607",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B2S4"             , "O2 Sensor Monitor Bank 2 - Sensor 4"            , "0608",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B3S1"             , "O2 Sensor Monitor Bank 3 - Sensor 1"            , "0609",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B3S2"             , "O2 Sensor Monitor Bank 3 - Sensor 2"            , "060A",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B3S3"             , "O2 Sensor Monitor Bank 3 - Sensor 3"            , "060B",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B3S4"             , "O2 Sensor Monitor Bank 3 - Sensor 4"            , "060C",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B4S1"             , "O2 Sensor Monitor Bank 4 - Sensor 1"            , "060D",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B4S2"             , "O2 Sensor Monitor Bank 4 - Sensor 2"            , "060E",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B4S3"             , "O2 Sensor Monitor Bank 4 - Sensor 3"            , "060F",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_B4S4"             , "O2 Sensor Monitor Bank 4 - Sensor 4"            , "0610",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MIDS_B"                      , "Supported MIDs [21-40]"                         , "0620",   0, "pid",                   "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_CATALYST_B1"         , "Catalyst Monitor Bank 1"                        , "0621",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_CATALYST_B2"         , "Catalyst Monitor Bank 2"                        , "0622",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_CATALYST_B3"         , "Catalyst Monitor Bank 3"                        , "0623",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_CATALYST_B4"         , "Catalyst Monitor Bank 4"                        , "0624",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_EGR_B1"              , "EGR Monitor Bank 1"                             , "0631",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_EGR_B2"              , "EGR Monitor Bank 2"                             , "0632",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_EGR_B3"              , "EGR Monitor Bank 3"                             , "0633",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_EGR_B4"              , "EGR Monitor Bank 4"                             , "0634",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_VVT_B1"              , "VVT Monitor Bank 1"                             , "0635",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_VVT_B2"              , "VVT Monitor Bank 2"                             , "0636",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_VVT_B3"              , "VVT Monitor Bank 3"                             , "0637",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_VVT_B4"              , "VVT Monitor Bank 4"                             , "0638",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_EVAP_150"            , "EVAP Monitor (Cap Off / 0.150\")"               , "0639",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_EVAP_090"            , "EVAP Monitor (0.090\")"                         , "063A",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_EVAP_040"            , "EVAP Monitor (0.040\")"                         , "063B",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_EVAP_020"            , "EVAP Monitor (0.020\")"                         , "063C",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_PURGE_FLOW"          , "Purge Flow Monitor"                             , "063D",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MIDS_C"                      , "Supported MIDs [41-60]"                         , "0640",   0, "pid",                   "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B1S1"      , "O2 Sensor Heater Monitor Bank 1 - Sensor 1"     , "0641",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B1S2"      , "O2 Sensor Heater Monitor Bank 1 - Sensor 2"     , "0642",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B1S3"      , "O2 Sensor Heater Monitor Bank 1 - Sensor 3"     , "0643",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B1S4"      , "O2 Sensor Heater Monitor Bank 1 - Sensor 4"     , "0644",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B2S1"      , "O2 Sensor Heater Monitor Bank 2 - Sensor 1"     , "0645",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B2S2"      , "O2 Sensor Heater Monitor Bank 2 - Sensor 2"     , "0646",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B2S3"      , "O2 Sensor Heater Monitor Bank 2 - Sensor 3"     , "0647",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B2S4"      , "O2 Sensor Heater Monitor Bank 2 - Sensor 4"     , "0648",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B3S1"      , "O2 Sensor Heater Monitor Bank 3 - Sensor 1"     , "0649",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B3S2"      , "O2 Sensor Heater Monitor Bank 3 - Sensor 2"     , "064A",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B3S3"      , "O2 Sensor Heater Monitor Bank 3 - Sensor 3"     , "064B",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B3S4"      , "O2 Sensor Heater Monitor Bank 3 - Sensor 4"     , "064C",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B4S1"      , "O2 Sensor Heater Monitor Bank 4 - Sensor 1"     , "064D",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B4S2"      , "O2 Sensor Heater Monitor Bank 4 - Sensor 2"     , "064E",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B4S3"      , "O2 Sensor Heater Monitor Bank 4 - Sensor 3"     , "064F",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_O2_HEATER_B4S4"      , "O2 Sensor Heater Monitor Bank 4 - Sensor 4"     , "0650",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MIDS_D"                      , "Supported MIDs [61-80]"                         , "0660",   0, "pid",                   "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_HEATED_CATALYST_B1"  , "Heated Catalyst Monitor Bank 1"                 , "0661",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_HEATED_CATALYST_B2"  , "Heated Catalyst Monitor Bank 2"                 , "0662",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_HEATED_CATALYST_B3"  , "Heated Catalyst Monitor Bank 3"                 , "0663",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_HEATED_CATALYST_B4"  , "Heated Catalyst Monitor Bank 4"                 , "0664",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_SECONDARY_AIR_1"     , "Secondary Air Monitor 1"                        , "0671",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_SECONDARY_AIR_2"     , "Secondary Air Monitor 2"                        , "0672",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_SECONDARY_AIR_3"     , "Secondary Air Monitor 3"                        , "0673",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_SECONDARY_AIR_4"     , "Secondary Air Monitor 4"                        , "0674",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MIDS_E"                      , "Supported MIDs [81-A0]"                         , "0680",   0, "pid",                   "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_FUEL_SYSTEM_B1"      , "Fuel System Monitor Bank 1"                     , "0681",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_FUEL_SYSTEM_B2"      , "Fuel System Monitor Bank 2"                     , "0682",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_FUEL_SYSTEM_B3"      , "Fuel System Monitor Bank 3"                     , "0683",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_FUEL_SYSTEM_B4"      , "Fuel System Monitor Bank 4"                     , "0684",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_BOOST_PRESSURE_B1"   , "Boost Pressure Control Monitor Bank 1"          , "0685",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_BOOST_PRESSURE_B2"   , "Boost Pressure Control Monitor Bank 1"          , "0686",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_NOX_ABSORBER_B1"     , "NOx Absorber Monitor Bank 1"                    , "0690",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_NOX_ABSORBER_B2"     , "NOx Absorber Monitor Bank 2"                    , "0691",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_NOX_CATALYST_B1"     , "NOx Catalyst Monitor Bank 1"                    , "0698",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_NOX_CATALYST_B2"     , "NOx Catalyst Monitor Bank 2"                    , "0699",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MIDS_F"                      , "Supported MIDs [A1-C0]"                         , "06A0",   0, "pid",                   "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_GENERAL"     , "Misfire Monitor General Data"                   , "06A1",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_1"  , "Misfire Cylinder 1 Data"                        , "06A2",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_2"  , "Misfire Cylinder 2 Data"                        , "06A3",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_3"  , "Misfire Cylinder 3 Data"                        , "06A4",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_4"  , "Misfire Cylinder 4 Data"                        , "06A5",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_5"  , "Misfire Cylinder 5 Data"                        , "06A6",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_6"  , "Misfire Cylinder 6 Data"                        , "06A7",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_7"  , "Misfire Cylinder 7 Data"                        , "06A8",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_8"  , "Misfire Cylinder 8 Data"                        , "06A9",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_9"  , "Misfire Cylinder 9 Data"                        , "06AA",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_10" , "Misfire Cylinder 10 Data"                       , "06AB",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_11" , "Misfire Cylinder 11 Data"                       , "06AC",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_MISFIRE_CYLINDER_12" , "Misfire Cylinder 12 Data"                       , "06AD",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_PM_FILTER_B1"        , "PM Filter Monitor Bank 1"                       , "06B0",   0, "monitor",               "ECU.ALL",     false));
    _mode6.push_back(OBDCommand("MONITOR_PM_FILTER_B2"        , "PM Filter Monitor Bank 2"                       , "06B1",   0, "monitor",               "ECU.ALL",     false));

    _mode7.push_back(OBDCommand("GET_CURRENT_DTC"             , "Get DTCs from the current/last driving cycle"   , "07",   0, "dtc",                   "ECU.ALL",     false));

    _mode9.push_back(OBDCommand("PIDS_9A"                    , "Supported PIDs [01-20]"                  , "0900", 4, "pid",                   "ECU.ENGINE",  true));
    _mode9.push_back(OBDCommand("VIN_MESSAGE_COUNT"          , "VIN Message Count"                       , "0901", 1, "uas(0x01)",             "ECU.ENGINE",  true));
    _mode9.push_back(OBDCommand("VIN"                        , "Get Vehicle Identification Number"       , "0902", 20, "raw_string",           "ECU.ENGINE",  true));

    _misc.push_back(OBDCommand("ELM_VERSION"                , "ELM327 version string"                   , "ATI",  0, "raw_string",            "ECU.UNKNOWN", false));
    _misc.push_back(OBDCommand("ELM_VOLTAGE"                , "Voltage detected by OBD-II adapter"      , "ATRV", 0, "elm_voltage",           "ECU.UNKNOWN", false));
  }

  ~commands();

 private:
  std::vector<OBDCommand> _mode1;
  std::vector<OBDCommand> _mode2;
  std::vector<OBDCommand> _mode3;
  std::vector<OBDCommand> _mode4;
  std::vector<OBDCommand> _mode6;
  std::vector<OBDCommand> _mode7;
  std::vector<OBDCommand> _mode9;
  std::vector<OBDCommand> _misc;

};

#endif //OBD_CPP_COMMANDS_H
