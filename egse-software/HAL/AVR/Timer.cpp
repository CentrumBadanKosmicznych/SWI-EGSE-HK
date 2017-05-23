/*
 * Timer.cpp
 *
 * Created: 2016-04-15 12:56:49
 *  Author: Piotr Kuligowski
 */ 

#include "Timer.h"

Timer_t::Timer_t(){
}

void Timer_t::init(uint16_t time_ms){
	double target_time = time_ms*0.001;
	double timer_resolution = 1024.0/16000000.0;
	double timer_count = (target_time/timer_resolution)-1;
	uint16_t timer_set = static_cast<uint16_t>(round(timer_count));
	
	//Init timer
	cli();
	TCCR1A = 0;
	TCCR1B = 0;
	
	//Set desired timer count
	OCR1A = timer_set;
	
	//CTC turn on
	TCCR1B |= (1 << WGM12);
	
	//1024 prescaler set-up
	TCCR1B |= (1 << CS10);
	TCCR1B |= (1 << CS12);
	
	//Interrupts enable
	TIMSK1 |= (1 << OCIE1A);
	sei();
	
	DDRB = 0xFF;
	
}