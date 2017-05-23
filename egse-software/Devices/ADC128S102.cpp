/*
 * ADC128S102.cpp
 *
 * Created: 2016-04-03 17:51:25
 *  Author: Piotr Kuligowski
 */ 

#include "ADC128S102.h"


#define set(a, b) (a) |= (1 << (b))
#define reset(a, b) (a) &= ~(1 << (b))

ADC128S102_t::ADC128S102_t() {
	this->init();
}

void ADC128S102_t::init(){
	
}

uint16_t ADC128S102_t::getValue(uint8_t channel){
	uint8_t mask, l_byte, h_byte;
	uint16_t value;
	
	DDRB = 0xFF;
	set(PORTB, 0);
	
	SPI.init({SPI_t::SPI_idle_high, SPI_t::SPI_trailing_sample, SPI_t::SPI_MSB_First, SPI_t::SPI_Clk_Div_16});
	
	reset(PORTB, 0);
	
	mask = 0x7;
	channel = static_cast<uint8_t>(channel & mask);
	channel = channel << 3;
	h_byte = ADC_SPI.shift(channel);
	h_byte = static_cast<uint8_t>(h_byte & 0x0F);
	l_byte = ADC_SPI.shift(0);
	
	set(PORTB, 0);
	
	value = static_cast<uint16_t>((h_byte << 8)|l_byte);
	
	return value;
}

uint16_t ADC128S102_t::getOversampledValue(uint8_t channel){
	uint32_t sum=0;
	uint8_t oversamples=64;
	
	for(uint8_t i=0; i<oversamples; i++){
		sum = sum + this->getValue(channel);
	}
	
	return static_cast<uint16_t>(round(sum/oversamples));
}