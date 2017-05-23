/*
 * Hk.cpp
 *
 * Created: 2016-04-06 19:56:59
 *  Author: Piotr Kuligowski
 */ 

#include "Hk.h"

Hk_t::Hk_t() {
	this->init();
}

void Hk_t::init(void){
	MUX.init();
	ADC128.init();
}

void Hk_t::printHK(void){
	Serial0.printf(Commands.COMMAND_GET_ADC);
	Frame.printCommandDataSeparator();
	for(uint8_t cs=16; cs<48; cs++){
		MUX.select(cs);
		for (uint8_t channel=0; channel<4; channel++){
			_delay_ms(1);
			ADC128.getValue(channel);
			_delay_ms(5);

			if (!(cs==63&&channel==3)){
				Serial0.printf("%u", ADC128.getValue(channel));
				Frame.printParamSeparator();
			}
			else{
				Serial0.printf("%u", ADC128.getValue(channel));
				Frame.printCommandDataSeparator();
			}
		}
	}
	
	
	Serial0.printf("CheckSum\n");
}
