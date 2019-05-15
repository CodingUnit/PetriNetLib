#pragma once
#include "lib_incl.h"
#include "core_cm3.h"
	// ����� ������ ����� �� ������ ������� (������� �����)
	inline u8 LSB(u32 bits)
	{
		u32 rev = __RBIT(bits);
		return __CLZ(rev);
	}

	// ���������� ����� �� 24 � 32 ������ ��������
	inline s32 sign_extend24(s32 val)
	{
    // sbfx r0, r1, lsb, width
		return val & 0x800000 ? val | 0xFF000000 : val;
	}
