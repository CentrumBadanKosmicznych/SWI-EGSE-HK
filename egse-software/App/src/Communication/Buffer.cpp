/*
 * Buffer.cpp
 *
 * Created: 2016-04-06 18:57:11
 *  Author: Piotr Kuligowski
 */ 

#include "Buffer.h"

Buffer_t::Buffer_t() {
	this->clear();
}

uint8_t* Buffer_t::get(void){
	return buffer;
}
	
void Buffer_t::setByte(uint8_t index, uint8_t byte){
	buffer[index] = byte;
}

uint8_t Buffer_t::getByte(uint8_t index){
	return buffer[index];
}

void Buffer_t::clear(void){
	for(uint8_t i=0; i<255; i++){
		buffer[i]=0;
	}
}