/*
 * Commands.h
 *
 * Created: 2016-04-06 16:56:26
 *  Author: Piotr Kuligowski
 *  Changes: Pawe³ Korba (P.K.) 2017.07.03
 */ 


#ifndef COMMANDS_H_
#define COMMANDS_H_

class Commands_t {
 public:
	const char* COMMAND_GET_ADC = "{#@}GetADC";
	const char* COMMAND_SET_DAC = "{#@}SetDAC";
	const char* COMMAND_ENABLE_SW = "{#@}EnableSW";
	const char* COMMAND_DISABLE_SW = "{#@}DisableSW";
	const char* COMMAND_GET_VERSION = "{#@}GetVersion";
	const char* COMMAND_SET_MUX = "{#@}SetMUX"; //P.K. 2017.07.03
	const char* COMMAND_GET_VALUE = "{#@}GetValue"; //P.K. 2017.07.03		
	const char* REPLY_ERROR_UNDEFINED_COMMAND = "Error UndefinedCommand";
	const char* REPLY_ERROR_FRAME = "Error Frame";
	const char* REPLY_ERROR_FRAME_CHECKSUM = "Error Checksum";
	const char* REPLY_ERROR_INWALID_PARAMS = "Error InvalidParameters";
	const char* REPLY_ERROR_PARAM_OUT_OF_RANGE = "Error ParameterOutOfRange";
	const char* REPLY_SET_DAC = "SetDAC";
	const char* REPLY_SET_SW = "SetSW";
	const char* REPLY_GET_VERSION_0 = "JUICE/SWI/PSU/HK/DM\nEGSE uC Software\nVersion:";
	const char* REPLY_GET_VERSION_1 = "0.3\nDate: 2017-07-03\nAuthor: Piotr Kuligowski\n";
	const char* REPLY_GET_VERSION_2 = "Company: Space Research Centre Polish Academy";
	const char* REPLY_GET_VERSION_3 = " of Sciences\n";
};

#endif /* COMMANDS_H_ */