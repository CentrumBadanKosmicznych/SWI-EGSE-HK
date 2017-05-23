/*
 * Dac.cpp
 *
 * Created: 2016-04-06 20:44:31
 *  Author: Piotr Kuligowski
 */ 

#include "Dac.h"

Dac_t::Dac_t() {
	this->init();
}

void Dac_t::init(void){
	MUX.init();
	DAC121.init();
	MUX.select(21);

	for(uint8_t i=0; i<16; i++){
		this->parameters_actual[i]=2047;
		this->parameters_target[i]=2047;
	}
}

uint16_t Dac_t::power(uint8_t x, uint8_t y){
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

void Dac_t::setDAC(void){
	
	DAC121.setMode(DAC121S101_t::NORMAL_OPERATION);

	uint8_t parameter_index=15;
	uint8_t mux_address;
	for(uint8_t i=0; i<=parameter_index; i++){
		mux_address = parameter_index-i+((parameter_index-i) / 4);
		MUX.select(mux_address);
		DAC121.setValue(this->parameters_actual[i]);
	}
	
	MUX.select(21);
}

void Dac_t::setDACzeroes(void){
	uint8_t parameter_index=15;
	for(uint8_t i=0; i<=parameter_index; i++){
		this->parameters_actual[i]=2048;
	}
	
	this->setDAC();
}

void Dac_t::setDacChannel(uint8_t channel){
	DAC121.setMode(DAC121S101_t::NORMAL_OPERATION);

	uint8_t parameter_index=15;
	uint8_t mux_address = parameter_index-channel+((parameter_index-channel) / 4);
	MUX.select(mux_address);
	DAC121.setValue(this->parameters_actual[channel]);
	
	MUX.select(21);
}

bool Dac_t::updateRamp(void){
	bool out=false;	

	for(uint8_t i=0; i<16; i++){
		if(this->parameters_actual[i]!=this->parameters_target[i]){
			if(this->parameters_actual[i]>this->parameters_target[i])
				this->parameters_actual[i]--;
			else
				this->parameters_actual[i]++;
			out=true;
		}
	}

	return out;
}

bool Dac_t::loadValues(uint8_t * data_buffer){
	uint8_t start_index = String.lengthUpToTerminator(data_buffer, Frame.getCommandDataSeparator(), 0);
	start_index++;
	uint8_t stop_index = String.lengthUpToTerminator(data_buffer, Frame.getCommandDataSeparator(), start_index);
	stop_index--;
	
	if (start_index>=stop_index)
		return false;
		
	uint8_t power=0;
	uint8_t parameter_index=0;
	parameters_target[0]=0;
	
	for(uint8_t character=stop_index; character>=start_index; character--){
		if(String.isNumber(data_buffer[character])){
			parameters_target[parameter_index]=static_cast<uint16_t>(parameters_target[parameter_index]+String.toNumber(data_buffer[character])*(this->power(10,power)));
			power++;
		} else if(data_buffer[character]==Frame.getParamSeparator()){
			power = 0;
			parameter_index++;
			parameters_target[parameter_index] = 0;
		} else
			return false;
	}
	
	if(parameter_index!=15)
		return false;
	
	return true;
}