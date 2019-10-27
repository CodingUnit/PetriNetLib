#pragma once
#include "lib_incl.h"
#include "core_cm3.h"
	// число нижних нулей до первой единицы (порядок числа)
	inline u8 LSB(u32 bits)
	{
		u32 rev = __RBIT(bits);
		return __CLZ(rev);
	}

	// расширение знака из 24 в 32 битное значение
	inline s32 sign_extend24(s32 val)
	{
    // sbfx r0, r1, lsb, width
		return val & 0x800000 ? val | 0xFF000000 : val;
	}
