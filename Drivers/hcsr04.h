#ifndef __HCSR04_H__
#define __HCSR04_H__

#include "stm32f1xx_hal.h"
#include "main.h"

#define HCSR04_TRIG_HIGH HAL_GPIO_WritePin(HCSR04_TRIG_GPIO_Port,HCSR04_TRIG_Pin,GPIO_PIN_SET)
#define HCSR04_TRIG_LOW  HAL_GPIO_WritePin(HCSR04_TRIG_GPIO_Port,HCSR04_TRIG_Pin,GPIO_PIN_RESET)
#define HCSR04_ECHO	HAL_GPIO_ReadPin(HCSR04_ECHO_GPIO_Port,HCSR04_ECHO_Pin)

void HCSR04StartTrigStart(void);
void HCSR04_TimerFunc(uint8_t mode);
float HCSR04_GetDistance_Single(void);
float HCSR04_GetDistance_Repeatedly(uint8_t cnt);

#endif
