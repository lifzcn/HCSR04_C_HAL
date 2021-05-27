#include "hcsr04.h"
#include "main.h"
#include "tim.h"

void HCSR04StartTrigStart(void)
{
	HCSR04_TRIG_HIGH;
	HAL_Delay_us(20);
	HCSR04_TRIG_LOW;
}

void HCSR04_TimerFunc(uint8_t mode)
{
	if(mode)
	{
		__HAL_TIM_SetCounter(&htim1,0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

//���λ�ȡ��������
float HCSR04_GetDistance_Single(void)
{
	HCSR04StartTrigStart();
  while(!HCSR04_ECHO);
  HCSR04_TimerFunc(1);//������ʱ��
  while(HCSR04_ECHO);
  HCSR04_TimerFunc(0);//�رն�ʱ��
	return (__HAL_TIM_GetCounter(&htim1))/58.0;
}

//��ֵ�˲���С�������
float HCSR04_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
  for(int i =0;i<cnt;i++)
  {
		sum+=HCSR04_GetDistance_Single();
  }
	return sum/cnt;
}
