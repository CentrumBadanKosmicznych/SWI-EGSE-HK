/*
 * Hk.cpp
 *
 * Created: 2016-04-06 19:56:59
 *  Author: Piotr Kuligowski
 *  Changes: Pawe³ Korba (P.K.) 2017.07.03
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

//P.K. 2017.07.03 start
void Hk_t::SetMux(uint8_t cs){

  MUX.select(cs);
  _delay_ms(1);	
}

void Hk_t::GetValue(uint8_t channel) {
	
  // pierwszy pomiar pusty	
  _delay_ms(1);
  ADC128.getValue(channel);
  _delay_ms(5);	
  
 Serial0.printf("%u", ADC128.getValue(channel));
 Frame.printCommandDataSeparator();
  
  
}