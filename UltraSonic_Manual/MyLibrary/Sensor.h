/*
 * Sensor.h
 *
 *  Created on: Jun 3, 2022
 *      Author: frzxx
 */

#ifndef SENSOR_H_
#define SENSOR_H_
#include <stm32f4xx_hal.h>
#define TRIG_PIN_1 GPIO_PIN_9
#define TRIG_PORT_1 GPIOA
#define ECHO_PIN_1 GPIO_PIN_8
#define ECHO_PORT_1 GPIOA
uint32_t pMillis_1;
uint32_t Value1_1 = 0;
uint32_t Value2_1 = 0;
uint16_t Distance_1  = 0;
#define TRIG_PIN_2 GPIO_PIN_10
#define TRIG_PORT_2 GPIOB
#define ECHO_PIN_2 GPIO_PIN_4
#define ECHO_PORT_2 GPIOB
uint32_t pMillis_2;
uint32_t Value1_2 = 0;
uint32_t Value2_2 = 0;
uint16_t Distance_2  = 0;


#endif /* SENSOR_H_ */
