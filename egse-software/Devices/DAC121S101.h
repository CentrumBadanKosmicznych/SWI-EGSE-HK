/*
 * DAC121S101.h
 *
 * Created: 2016-04-01 21:16:50
 *  Author: Piotr Kuligowski
 */ 


#ifndef DAC121S101_H_
#define DAC121S101_H_

#include "SPI.h"
#include "GPIO.h"

class DAC121S101_t {
 public:
	 enum DAC_Mode {
		 NORMAL_OPERATION = 0,
		 POWER_DOWN_1K_TO_GND = 1,
		 POWER_DOWN_100K_TO_GND = 2,
		 POWER_DOWN_HIGH_IMPEDANCE = 3
	 };

    /*
     * @brief Initialization of the device.
     * @param InitStruct: Contains all information needed for device initialization.
     * @retval None
     */
    void init();

    /*
     * @brief Set the DAC output value.
     * @param value: New value at output. Range 0-4095.
     * @retval None
     */
    void setValue(uint16_t value);
	
	/*
     * @brief Set the mode of operation.
     * @param mode: New mode.
     * @retval None
     */
	void setMode(DAC_Mode mode);
	
	explicit DAC121S101_t();
	
 private:
	 DAC_Mode actual_mode;
	 //Timer_t timer;
};

#endif /* DAC121S101_H_ */