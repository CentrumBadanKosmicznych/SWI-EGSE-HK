/*
 * Switches.cpp
 *
 * Created: 2017-04-19 20:24:03
 *  Author: pkuligowski
 */ 

#include "Switches.h"

#define set(a, b) (a) |= (1 << (b))
#define reset(a, b) (a) &= ~(1 << (b))

Switches_t::Switches_t() {
	this->init();
}

void Switches_t::init(void){
	DDRC = 0xFF;
	DDRA = 0xFF;
	
	reset(PORTA, 0);
	reset(PORTA, 1);
	reset(PORTA, 2);
	reset(PORTA, 3);
	reset(PORTA, 4);
	reset(PORTA, 5);
	reset(PORTA, 6);
	reset(PORTA, 7);
	
	reset(PORTC, 0);
	reset(PORTC, 1);
	reset(PORTC, 2);
}

void Switches_t::enableOneSwitch(uint8_t switch_id){
	if (switch_id<8){
		set(PORTA, switch_id);
	} else if (switch_id<16){
		set(PORTC, (switch_id-8));
	}
}

void Switches_t::disableOneSwitch(uint8_t switch_id){
	if (switch_id<8){
		reset(PORTA, switch_id);
	} else if (switch_id<16){
		reset(PORTC, (switch_id-8));
	}
}

void Switches_t::disableAllSwitches(void){
		reset(PORTA, 0);
		reset(PORTA, 1);
		reset(PORTA, 2);
		reset(PORTA, 3);
		reset(PORTA, 4);
		reset(PORTA, 5);
		reset(PORTA, 6);
		reset(PORTA, 7);
		
		reset(PORTC, 0);
		reset(PORTC, 1);
		reset(PORTC, 2);
}

void Switches_t::enableAllSwitches(void){
		set(PORTA, 0);
		set(PORTA, 1);
		set(PORTA, 2);
		set(PORTA, 3);
		set(PORTA, 4);
		set(PORTA, 5);
		set(PORTA, 6);
		set(PORTA, 7);
		
		set(PORTC, 0);
		set(PORTC, 1);
		set(PORTC, 2);
}

int Switches_t::loadParameter(uint8_t * data_buffer){
	uint8_t start_index = String.lengthUpToTerminator(data_buffer, Frame.getCommandDataSeparator(), 0);
	start_index++;
	uint8_t stop_index = String.lengthUpToTerminator(data_buffer, Frame.getCommandDataSeparator(), start_index);
	stop_index--;
	
	if (start_index>stop_index)
	return -1;

	uint8_t power=0;
	uint8_t parameter_index=0;
	parameters[0]=0;
	
	for(uint8_t character=stop_index; character>=start_index; character--){
		if(String.isNumber(data_buffer[character])){
			parameters[parameter_index]=static_cast<uint16_t>(parameters[parameter_index]+String.toNumber(data_buffer[character])*(this->power(10,power)));
			power++;
		} else if(data_buffer[character]==Frame.getParamSeparator()){
			power = 0;
			parameter_index++;
			parameters[parameter_index] = 0;
		} else
			return -2;
	}
	
	return parameters[0];
}

uint16_t Switches_t::power(uint8_t x, uint8_t y){
	uint16_t out=x;
	
	if(y==0)
	return 1;
	else {
		for(uint8_t i=y; i>1; i--){
			out=out*x;
		}
		return out;
	}
}