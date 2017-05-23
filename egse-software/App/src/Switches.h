/*
 * Switches.h
 *
 * Created: 2017-04-19 20:24:12
 *  Author: pkuligowski
 */ 


#ifndef SWITCHES_H_
#define SWITCHES_H_

#include <avr/io.h>
#include <stdlib.h>
#include "String.h"
//#include "Serial.h"
#include "Communication/Frame.h"
//#include "Communication/Commands.h"

class Switches_t {
	public:
		void init(void);

		void enableOneSwitch(uint8_t switch_id);
		void disableOneSwitch(uint8_t switch_id);
		void disableAllSwitches(void);
		void enableAllSwitches(void);
		int loadParameter(uint8_t * data_buffer);
		uint16_t power(uint8_t x, uint8_t y);
		
		explicit Switches_t();
		
		enum SWITCH_ID {
			SWITCH_REF = 0,
			SWITCH_CTS1 = 1,
			SWITCH_CTS2 = 2,
			SWITCH_IF_COMB = 3,
			SWITCH_ACS1 = 4,
			SWITCH_ACS2 = 5,
			SWITCH_CCH = 6,
			SWITCH_MOT = 7,
			SWITCH_HNF = 8,
			SWITCH_AT_RED = 9,
			SWITCH_CT_RED = 10
		};
		
	private:
		uint16_t parameters[3];
		Frame_t Frame;
		String_t String;
};


#endif /* SWITCHES_H_ */