/*
 * Buffer.h
 *
 * Created: 2016-04-06 18:57:02
 *  Author: Piotr Kuligowski
 */ 


#ifndef BUFFER_H_
#define BUFFER_H_

#include <avr/io.h>
#include <stdlib.h>

class Buffer_t {
 public:
	void clear(void);
	
	uint8_t* get(void);
	
	void setByte(uint8_t index, uint8_t byte);
	
	uint8_t getByte(uint8_t index);

	explicit Buffer_t();
	
 private:
	uint8_t buffer[255];
	
};

#endif /* BUFFER_H_ */