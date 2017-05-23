/*
 * Frame.h
 *
 * Created: 2016-04-06 16:52:12
 *  Author: Piotr Kuligowski
 */ 


#ifndef FRAME_H_
#define FRAME_H_

#include <avr/io.h>
#include <stdlib.h>

#include "String.h"
#include "Serial.h"

class Frame_t {
 public:
	bool headerIsValid(uint8_t * data_buffer);
	
	uint8_t readFrame(uint8_t * data_buffer);
	
	void printTerminator(void);
	
	void printHeader(void);
	
	void printFrame(const char* frame);
	
	void printCommandDataSeparator(void);
	uint8_t getCommandDataSeparator(void);
	
	void printParamSeparator(void);
	uint8_t getParamSeparator(void);
	
	bool receivedCommand(uint8_t * data_buffer, uint8_t data_bytes, const char* command);
	
	explicit Frame_t();
 private:
	const char* FRAME_HEADER = "{#@}";
	const uint8_t FRAME_TERMINATOR = 0xA;
	const uint8_t FRAME_COMMAND_DATA_SEPARATOR = 0x20;
	const uint8_t FRAME_PARAM_SEPARATOR = ',';
};

#endif /* FRAME_H_ */