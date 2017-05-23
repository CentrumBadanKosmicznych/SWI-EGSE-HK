/*
 * board.h
 *
 * Created: 2016-04-03 16:58:20
 *  Author: Piotr Kuligowski
 */ 

#ifndef BOARDS_SWI_PSU_BIAS_DM1_H_
#define BOARDS_SWI_PSU_BIAS_DM1_H_

/* HAL include */
#include "pins.h"
#include "GPIO.h"
#include "SPI.h"
#include "Serial.h"

/* Devices include */
#include "../../Devices/MAX306EWIdouble.h"
#include "../../Devices/DAC121S101.h"
#include "../../Devices/ADC128S102.h"

/* 24 ChipSelect MUX */
//const ADG709_t::InitTypeDef_t MUX_MOS = {46, 44, 47};

/* SPI CS MUX */

/* DAC */

/* ADC */

class BOARDS_SWI_PSU_BIAS_DM1_t {
 public:
    /*
     * @brief Initialization of the board.
     * @param InitStruct: Contains all information needed for device initialization.
     * @retval None
     */
    void init();
	
	explicit BOARDS_SWI_PSU_BIAS_DM1_t();
};

#endif  //  BOARDS_SWI_PSU_BIAS_DM1_H_
