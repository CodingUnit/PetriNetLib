#pragma once
#include "stm32f1xx_hal.h"

class global_time
{
  u32  counter_intime;
  u32  temp_counter_intime;
  //volatile unsigned long long  temp_counter_intime = 0;
  TIM_HandleTypeDef *htim_cntr;
public:
  global_time()
  {
    counter_intime = temp_counter_intime = 0;    
  }
  
	static u64 time()
	{
		return get_instance().get_time();
	}

  static global_time &get_instance()
  {
    static global_time time;
    return time;
  }
  // �������� ������� ����� � �������������
  u64 get_time() const
  {
    u32 save;
    u32 cnt;
    // ��������� ������� �����, ���� ������ ����������� ����� ���������� �����
    // ������ ���������� ������������ �������
    // ������ ������� �����, ������ �������, ������ �������, ���� ������� ���������� �������� ����� ������ �������
    // ���� � ��� ����� ����������� ������, ������� ��� ���� ������������ ����������

    if (temp_counter_intime != counter_intime) 
    { 
      cnt = __HAL_TIM_GET_COUNTER(htim_cntr);
      save = temp_counter_intime;
    } else 
    {
      u32 flag = __HAL_TIM_GET_FLAG(htim_cntr, TIM_FLAG_UPDATE) != 0; // ������ ����, 
      cnt = __HAL_TIM_GET_COUNTER(htim_cntr); // ��������� �������
      u32 flag2 = __HAL_TIM_GET_FLAG(htim_cntr, TIM_FLAG_UPDATE) != 0; // ������ ��������
      if (flag != flag2) // ���������� ��� �����, ���� ������ ������������ � ���� ���������, ���� �������� ������ ����� ��� ���
      {
        cnt = __HAL_TIM_GET_COUNTER(htim_cntr); // ��������� ������� ������ ���
      }
      save = counter_intime + flag2;
    }

    u64 res = (u64)(save) << 16;
    u64 time = res + cnt; // ������ + ������� ����� ��������������� �������
    return time;
  }
  
  void update_time()
  {
    if (__HAL_TIM_GET_FLAG(htim_cntr, TIM_FLAG_UPDATE)) // ������ ����
    {
      u32 time = counter_intime + 1; // ��������� ������� �����
      temp_counter_intime = time; // ��������� ������� ����� �� ��������� ����������
      //cli();
      __HAL_TIM_CLEAR_FLAG(htim_cntr, TIM_FLAG_UPDATE); // ���������� ���� ������������ �������
			counter_intime = time; // ��������� ������������� �������� � �������
    }
  }
  
  void init(TIM_HandleTypeDef *mcs_timer)
  {
    	htim_cntr = mcs_timer;
      HAL_TIM_Base_Start(htim_cntr);
  }
};