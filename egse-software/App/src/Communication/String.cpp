/*
 * String.cpp
 *
 * Created: 2016-04-06 16:20:06
 *  Author: Piotr Kuligowski
 */ 

#include "String.h"

String_t::String_t() {
}

bool String_t::compare(uint8_t * string_a, const char * string_b, uint8_t ln){
	for(uint8_t i=0; i<ln; i++){
		if(!(string_a[i]==string_b[i]))
		return false;
	}
	return true;
}

bool String_t::compareUpToTerminator(uint8_t * string_a, const char * string_b, uint8_t ln, const uint8_t terminator){
	for(uint8_t i=0; i<ln; i++){
		if (string_a[i]==terminator)
			return true;
		if(!(string_a[i]==string_b[i]))
			return false;
	}
	return true;
}

uint8_t String_t::length(const char * string){
	uint8_t i=0;
	for(i=0; string[i]<255; i++){
		if (string[i]==0)
		break;
	}
	return i;
}

uint8_t String_t::lengthUpToTerminator(uint8_t * string, const uint8_t terminator){
	return this->lengthUpToTerminator(string, terminator, 0);
}

uint8_t String_t::lengthUpToTerminator(uint8_t * string, const uint8_t terminator, uint8_t start_index){
	uint8_t i=0;
	for(i=start_index; string[i]<255; i++){
		if (string[i]==0)
		return i-1;
		if (string[i]==terminator)
		return i;
	}
	return i;
}

bool String_t::isNumber(uint8_t character){
	if ((character>=48)&(character<=57))
		return true;
	else
		return false;
}

uint8_t String_t::toNumber(uint8_t character){
	if (this->isNumber(character))
		return (character-48);
	else
		return 0;
}