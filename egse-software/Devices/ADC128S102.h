/*
 * ADC128S102.h
 *
 * Created: 2016-04-03 17:51:08
 *  Author: Piotr Kuligowski
 */ 


#ifndef ADC128S102_H_
#define ADC128S102_H_

#include "SPI.h"

#include <avr/io.h>
#include <stdlib.h>
#include <math.h>

class ADC128S102_t {
 public:
    /*
     * @brief Initialization of the device.
     * @param InitStruct: Contains all information needed for device initialization.
     * @retval None
     */
    void init();

    /*
     * @brief Get ADC's input value.
     * @param channel: Selected channel. Range 0-7.
     * @retval ADC's value. Range 0-4095.
     */
    uint16_t getValue(uint8_t channel);
	
	uint16_t getOversampledValue(uint8_t channel);
	
	explicit ADC128S102_t();
	
 private:
	 //DAC_Mode actual_mode;
	 SPI_Device_t ADC_SPI;
};

#endif /* ADC128S102_H_ */