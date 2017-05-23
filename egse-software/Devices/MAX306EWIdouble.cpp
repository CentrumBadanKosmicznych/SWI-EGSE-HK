/*
 * MAX306EWIdouble.cpp
 *
 * Created: 2017-04-19 19:41:03
 *  Author: pkuligowski
 */ 

#include "MAX306EWIdouble.h"

#define set(a, b) (a) |= (1 << (b))
#define reset(a, b) (a) &= ~(1 << (b))

MAX306EWIdouble_t::MAX306EWIdouble_t() {
	this->init();
}

void MAX306EWIdouble_t::init(){
	DDRF = 0xFF;
	reset(PORTF, 0);
	reset(PORTF, 1);
	reset(PORTF, 2);
	reset(PORTF, 3);
	reset(PORTF, 4);
	reset(PORTF, 5);
}

void MAX306EWIdouble_t::select(uint8_t channel) {
	if (channel>63)
		channel = 63;
	
	uint8_t mask=1;
	if (static_cast<bool>(channel & mask))
		set(PORTF, 2);
	else
		reset(PORTF, 2);
	
	mask=2;
	if ((channel & (mask)))
		set(PORTF, 3);
	else
		reset(PORTF, 3);
	
	mask=4;
	if ((channel & (mask)))
		set(PORTF, 4);
	else
		reset(PORTF, 4);
	
	mask=8;
	if ((channel & (mask)))
		set(PORTF, 5);
	else
		reset(PORTF, 5);
	
	mask=16;
	if ((channel & (mask)))
		set(PORTF, 0);
	else
		reset(PORTF, 0);
		
	mask=32;
	if ((channel & (mask)))
		set(PORTF, 1);
	else
		reset(PORTF, 1);
}
