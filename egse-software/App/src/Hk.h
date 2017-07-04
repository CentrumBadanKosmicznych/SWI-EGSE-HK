/*
 * Hk.h
 *
 * Created: 2016-04-06 19:58:19
 *  Author: Piotr Kuligowski
 *  Changes: Pawe³ Korba (P.K.) 2017.07.03
 */ 

#ifndef HK_H_
#define HK_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "../../Boards/SWI-PSU-BIAS-DM1/board.h"
#include "String.h"
#include "Serial.h"
#include "Communication/Frame.h"
#include "Communication/Commands.h"

class Hk_t {
 public:
	void printHK(void);
	
	void init(void);
	void SetMux(uint8_t);
	void GetValue(uint8_t);
	
	explicit Hk_t();
	
 private:
	ADC128S102_t ADC128;
	MAX306EWIdouble_t MUX;
	Frame_t Frame;
	Commands_t Commands;
};

#endif /* HK_H_ */