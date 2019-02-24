#include "atomic.h"

u8 CAS(volatile u32 * pAddr, u32 nExpected, u32 nNew)
{
	if (LL(pAddr) == nExpected)
		return SC(pAddr, nNew);
	return 0;
}

u8 CAS16(volatile u16 * pAddr, u16 nExpected, u16 nNew)
{
	if (LL16(pAddr) == nExpected)
		return SC16(pAddr, nNew);
	return 0;
}

u8 CAS8(volatile u8 *pAddr, u8 nExpected, u8 nNew)
{
	if (LL8(pAddr) == nExpected)
		return SC8(pAddr, nNew);
	return 0;
}

u32 FAA(u32 *adr, s32 inc)
{
	u32 cur;
	do
	{
		cur = *adr;
	} while (!CAS(adr, cur, cur + inc));
	return cur;
}

u16 FAA16(u16 *adr, s32 inc)
{
	u16 cur;
	do
	{
		cur = *adr;
	} while (!CAS16(adr, cur, cur + inc));
	return cur;
}

u8 FAA8(u8 *adr, s8 inc)
{
	u8 cur;
	do
	{
		cur = *adr;
	} while (!CAS8(adr, cur, cur + inc));
	return cur;
}
u32 atomic_or(u32 *addr, u32 val)
{
	u32 cur;
	do
	{
		cur = *addr;
	} while (!CAS(addr, cur, cur | val));
	return cur;
}

u32 atomic_and(u32 *addr, u32 val)
{
	u32 cur;
	do
	{
		cur = *addr;
	} while (!CAS(addr, cur, cur & val));
	return cur;
}

