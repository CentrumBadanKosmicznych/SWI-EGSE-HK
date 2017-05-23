/*
 * Timer.h
 *
 * Created: 2016-04-15 12:57:14
 *  Author: Piotr Kuligowski
 */ 

#include <stdint.h>
#include <avr/interrupt.h>
#include <math.h>

#ifndef TIMER_H_
#define TIMER_H_

class Timer_t {
 public:
	void init(uint16_t time_ms);
	
	explicit Timer_t();
	
};

#endif /* TIMER_H_ */