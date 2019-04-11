#pragma once

namespace math
{
	class Math
	{

	public:

	  static u32 UpperDiv(u32 val, u32 div)
    {
        return (val + div - 1) / div;
    }

		static s16 NearDiv16(s16 val, s16 div)
    {
        return (val * 2 + div) / (div * 2);
    }

		static s32 NearDiv(s32 val, s32 div)
    {
        return (val * 2 + div) / (div * 2);
    }
	};
}