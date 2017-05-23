/*
 * Dac.h
 *
 * Created: 2016-04-06 20:44:21
 *  Author: Piotr Kuligowski
 */ 


#ifndef DAC_H_
#define DAC_H_

#include "../../Boards/SWI-PSU-BIAS-DM1/board.h"
#include "String.h"
#include "Serial.h"
#include "Communication/Frame.h"
#include "Communication/Commands.h"
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

class Dac_t {
 public:
	void init(void);
	
	bool loadValues(uint8_t * data_buffer);
	
	uint16_t power(uint8_t x, uint8_t y);
	bool updateRamp(void);
	void setDAC(void);
	void setDACzeroes(void);
	void setDacChannel(uint8_t channel);
	
	explicit Dac_t();
	
 private:
	DAC121S101_t DAC121;
	MAX306EWIdouble_t MUX;
	Frame_t Frame;
	Commands_t Commands;
	String_t String;
	uint16_t parameters_target[24], parameters_actual[24];
};

#endif /* DAC_H_ */