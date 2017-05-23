/*
 * SN74HC138N_triple.h
 *
 * Created: 2016-04-01 12:06:56
 *  Author: Piotr Kuligowski
 */ 


#ifndef SN74HC138NTRIPLE_H_
#define SN74HC138NTRIPLE_H_

#include "GPIO.h"
#include "pins.h"

/*
 * @class SN74HC138Ntriple_t
 * @brief Class is used to provide user-friendly solutions for SPI slaves muxing based on triple SN74HC138N.
 * @details Class selects SPI slave.
 */

class SN74HC138Ntriple_t {
 private:
    GPIOPin_t A0, A1, A2, EN0, EN1;

 public:
    explicit SN74HC138Ntriple_t();

    /*
     * @brief Initialization of the device.
     * @param InitStruct: Contains all information needed for device initialization.
     * @retval None
     */
    void init();

    /*
     * @brief Select CS slave.
     * @detailed Enable/disable methods are higher in hierarchy.
     * @param channel: Determines a number of channel to be chosen. Range 0-23.
     * @retval None
     */
    void select(uint8_t channel);
};

#endif /* SN74HC138NTRIPLE_H_ */