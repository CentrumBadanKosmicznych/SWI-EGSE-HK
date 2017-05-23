/*
 * app.h
 *
 * Created: 2016-04-05 03:22:25
 *  Author: Piotr Kuligowski
 */ 


#ifndef APP_H_
#define APP_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "../../Boards/SWI-PSU-BIAS-DM1/board.h"
#include "Communication/String.h"
#include "Communication/Frame.h"
#include "Communication/Buffer.h"
#include "Communication/Commands.h"
//#include "../../HAL/AVR/Timer.h"
#include "Hk.h"
#include "Dac.h"
#include "Switches.h"

void begin(void);

void init(void);

#endif /* APP_H_ */

