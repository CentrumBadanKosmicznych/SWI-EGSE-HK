/*
 * String.h
 *
 * Created: 2016-04-06 16:19:40
 *  Author: pkuligowski
 */ 


#ifndef STRING_H_
#define STRING_H_

#include <avr/io.h>
#include <stdlib.h>

class String_t {
 public:
	/*
     * @brief uint8_t * and const char* comparision.
     * @param string_a: A pointer to data buffer. uint8_t* type.
	 * @param string_b: A pointer to const char*.
	 * @param ln: Number of characters to comparision.
     * @retval Strings are equal or not. true/false type.
     */
	bool compare(uint8_t * string_a, const char * string_b, uint8_t ln);
	
	bool compareUpToTerminator(uint8_t * string_a, const char * string_b, uint8_t ln, const uint8_t terminator);
	
	/*
     * @brief const char* length.
     * @param string: a string to count.
     * @retval Number of characters.
     */
	uint8_t length(const char * string);
	
	uint8_t lengthUpToTerminator(uint8_t * string, const uint8_t terminator);
	
	uint8_t lengthUpToTerminator(uint8_t * string, const uint8_t terminator, uint8_t start_index);
	
	bool isNumber(uint8_t character);
	
	uint8_t toNumber(uint8_t character);
	
	explicit String_t();
};

#endif /* STRING_H_ */