/*
 * Frame.cpp
 *
 * Created: 2016-04-06 16:52:02
 *  Author: Piotr Kuligowski
 */ 

#include "Frame.h"

Frame_t::Frame_t() {
}

bool Frame_t::headerIsValid(uint8_t * data_buffer){
	String_t String;
	return String.compare(data_buffer, this->FRAME_HEADER, String.length(this->FRAME_HEADER));
}

uint8_t Frame_t::readFrame(uint8_t * data_buffer){
	uint8_t max_length=255, data_bytes;
	data_bytes = Serial0.read_byte_array_until_term(data_buffer, this->FRAME_TERMINATOR, max_length);
	data_bytes--;
	return data_bytes;
}

void Frame_t::printTerminator(void){
	Serial0.print_byte(this->FRAME_TERMINATOR);
}

void Frame_t::printHeader(void){
	String_t String;
	for(uint8_t i=0; i<String.length(this->FRAME_HEADER); i++){
		Serial0.print_byte(this->FRAME_HEADER[i]);
	}
}

void Frame_t::printFrame(const char* frame){
	this->printHeader();
	Serial0.printf(frame);
	this->printTerminator();
}

void Frame_t::printCommandDataSeparator(void){
	Serial0.print_byte(this->FRAME_COMMAND_DATA_SEPARATOR);
}

uint8_t Frame_t::getCommandDataSeparator(void){
	return this->FRAME_COMMAND_DATA_SEPARATOR;
}

void Frame_t::printParamSeparator(){
	Serial0.print_byte(this->FRAME_PARAM_SEPARATOR);
}

uint8_t Frame_t::getParamSeparator(void){
	return this->FRAME_PARAM_SEPARATOR;
}

bool Frame_t::receivedCommand(uint8_t * data_buffer, uint8_t data_bytes, const char* command){
	String_t String;
	return	(String.length(command)==String.lengthUpToTerminator(data_buffer, this->FRAME_COMMAND_DATA_SEPARATOR))
			&(String.compareUpToTerminator(data_buffer, command, data_bytes, this->FRAME_COMMAND_DATA_SEPARATOR));
}

