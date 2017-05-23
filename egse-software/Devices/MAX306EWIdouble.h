/*
 * MAX306EWIdouble.h
 *
 * Created: 2017-04-19 19:41:14
 *  Author: pkuligowski
 */ 


#ifndef MAX306EWIDOUBLE_H_
#define MAX306EWIDOUBLE_H_

#include "GPIO.h"
#include "pins.h"

class MAX306EWIdouble_t {
 private:
    GPIOPin_t A0, A1, A2, EN0, EN1;

 public:
    explicit MAX306EWIdouble_t();

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


#endif /* MAX306EWIDOUBLE_H_ */