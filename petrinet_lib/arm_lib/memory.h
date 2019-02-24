#pragma once
#include "include.h"
#include "arm_lib_hal\memory.h"

namespace memory
{

	class Mem
	{
	public:

		static void copy(void *dest, const void *src, int size)
		{
			u8 *source = (u8 *)src;
			u8 *dst = (u8 *)dest;
			for (int i = 0; i < size; )
			{
				if (size - i < 4)
				{
					*(u8 *)dst = *(u8 *)source;
          dst++;
          source++;
					i++;
				} else
				{
					*(u32 *)dst = *(u32 *)source;
          dst+=4;
          source+=4;
					i += 4;
				}
			}
		}

		static void copy32(void *dest, const void *src, int size)
		{
			u32 *source = (u32 *)src;
			u32 *dst = (u32 *)dest;
			for (int i = 0; i < size; i += 4)
			{
				*dst++ = *source++;
			}
		}
	};
  
}
