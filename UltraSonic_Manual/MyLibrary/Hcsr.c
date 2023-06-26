/*
 * Hcsr.c
 *
 *  Created on: Jun 3, 2022
 *      Author: frzxx
 */

#include <Sensor.h>
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_tim.h>
#include <stm32f4xx_hal_gpio.h>

extern TIM_HandleTypeDef htim3;


void HCSR_Read_1(void){
    HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_SET);  // pull the TRIG pin HIGH
    __HAL_TIM_SET_COUNTER(&htim3, 0);
    while (__HAL_TIM_GET_COUNTER (&htim3) < 10);  // wait for 10 us
    HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_RESET);  // pull the TRIG pin low

    pMillis_1 = HAL_GetTick(); // used this to avoid infinite while loop  (for timeout)
    // wait for the echo pin to go high
    while (!(HAL_GPIO_ReadPin (ECHO_PORT_1, ECHO_PIN_1)) && pMillis_1 + 10 >  HAL_GetTick());
    Value1_1 = __HAL_TIM_GET_COUNTER (&htim3);

    pMillis_1 = HAL_GetTick(); // used this to avoid infinite while loop (for timeout)
    // wait for the echo pin to go low
    while ((HAL_GPIO_ReadPin (ECHO_PORT_1, ECHO_PIN_1)) && pMillis_1 + 50 > HAL_GetTick());
    Value2_1 = __HAL_TIM_GET_COUNTER (&htim3);

    Distance_1 = (Value2_1-Value1_1)* 0.034/2;
    HAL_Delay(50);
}

void HCSR_Read_2(void){
    HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_SET);  // pull the TRIG pin HIGH
    __HAL_TIM_SET_COUNTER(&htim3, 0);
    while (__HAL_TIM_GET_COUNTER (&htim3) < 10);  // wait for 10 us
    HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_RESET);  // pull the TRIG pin low

    pMillis_2 = HAL_GetTick(); // used this to avoid infinite while loop  (for timeout)
    // wait for the echo pin to go high
    while (!(HAL_GPIO_ReadPin (ECHO_PORT_2, ECHO_PIN_2)) && pMillis_2 + 10 >  HAL_GetTick());
    Value1_2 = __HAL_TIM_GET_COUNTER (&htim3);

    pMillis_2 = HAL_GetTick(); // used this to avoid infinite while loop (for timeout)
    // wait for the echo pin to go low
    while ((HAL_GPIO_ReadPin (ECHO_PORT_2, ECHO_PIN_2)) && pMillis_2 + 50 > HAL_GetTick());
    Value2_2 = __HAL_TIM_GET_COUNTER (&htim3);

    Distance_2 = (Value2_2-Value1_2)* 0.034/2;
    HAL_Delay(50);
}
