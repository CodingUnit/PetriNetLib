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
  // получаем текущее время в микросекундах
  u64 get_time() const
  {
    u32 save;
    u32 cnt;
    // сохраняем текущее время, если таймер обновляется берем предыдущее время
    // читаем непрерывно изменяющийся счетчик
    // читаем старшую часть, читаем младшую, читаем старшую, если старшая изменилась начинаем снова читать младшую
    // если в это время обновляется таймер, считаем что флаг переполнения установлен

    if (temp_counter_intime != counter_intime) 
    { 
      cnt = __HAL_TIM_GET_COUNTER(htim_cntr);
      save = temp_counter_intime;
    } else 
    {
      u32 flag = __HAL_TIM_GET_FLAG(htim_cntr, TIM_FLAG_UPDATE) != 0; // читаем флаг, 
      cnt = __HAL_TIM_GET_COUNTER(htim_cntr); // сохраняем счетчик
      u32 flag2 = __HAL_TIM_GET_FLAG(htim_cntr, TIM_FLAG_UPDATE) != 0; // читаем повторно
      if (flag != flag2) // сравниваем два флага, если таймер переполнился и флаг изменился, надо прочесть нижнюю часть еще раз
      {
        cnt = __HAL_TIM_GET_COUNTER(htim_cntr); // сохраняем счетчик второй раз
      }
      save = counter_intime + flag2;
    }

    u64 res = (u64)(save) << 16;
    u64 time = res + cnt; // старое + текущее время микросекундного таймера
    return time;
  }
  
  void update_time()
  {
    if (__HAL_TIM_GET_FLAG(htim_cntr, TIM_FLAG_UPDATE)) // читаем флаг
    {
      u32 time = counter_intime + 1; // считываем текущее время
      temp_counter_intime = time; // сохраняем текущее время во временной переменной
      //cli();
      __HAL_TIM_CLEAR_FLAG(htim_cntr, TIM_FLAG_UPDATE); // сбрасываем флаг переполнения таймера
			counter_intime = time; // добавляем переполненное значение в счетчик
    }
  }
  
  void init(TIM_HandleTypeDef *mcs_timer)
  {
    	htim_cntr = mcs_timer;
      HAL_TIM_Base_Start(htim_cntr);
  }
};