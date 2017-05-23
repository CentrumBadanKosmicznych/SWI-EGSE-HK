/*
 * SN74HC138N_triple.cpp
 *
 * Created: 2016-04-01 12:06:00
 *  Author: Piotr Kuligowski
 */ 

#include "SN74HC138Ntriple.h"

#define set(a, b) (a) |= (1 << (b))
#define reset(a, b) (a) &= ~(1 << (b))

SN74HC138Ntriple_t::SN74HC138Ntriple_t() {
	this->init();
}

void SN74HC138Ntriple_t::init(){
	DDRL = 0xFF;
	set(PORTL, 0);
	set(PORTL, 1);
	set(PORTL, 2);
	set(PORTL, 3);
	set(PORTL, 4);
}

void SN74HC138Ntriple_t::select(uint8_t channel) {
	uint8_t mask=1;
	if (static_cast<bool>(channel & mask))
		set(PORTL, 0);
	else
		reset(PORTL, 0);
	
	mask=2;
	if ((channel & (mask)))
		set(PORTL, 1);
	else
		reset(PORTL, 1);
	
	mask=4;
	if ((channel & (mask)))
		set(PORTL, 2);
	else
		reset(PORTL, 2);
	
	mask=8;
	if ((channel & (mask)))
		set(PORTL, 3);
	else
		reset(PORTL, 3);
	
	mask=16;
	if ((channel & (mask)))
		set(PORTL, 4);
	else
		reset(PORTL, 4);
}
