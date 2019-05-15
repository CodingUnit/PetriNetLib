#pragma once
#include "lib_incl.h"
//#include "include.h"
#include "stm32f1xx.h"
#include "core_cm3.h"
//#include "intrinsics.h"
//#include "cmsis_iar.h"

#ifdef __cplusplus
extern "C" {
#endif

// читает данные по адресу и выставляет эксклюзивный флаг
inline u32 LL(const volatile u32 *pAddr) 
{
      return __LDREXW((volatile u32 *)pAddr);
}

// 1 - если запись произведена
inline u8 SC(volatile u32 *pAddr, u32 New ) 
{
	return !__STREXW(New, pAddr);
}

inline u8 LL8(volatile u8 *pAddr)
{
      return __LDREXB(pAddr);
}

// 1 - если запись произведена
inline u8 SC8(volatile u8 *pAddr, u8 New) 
{
	return !__STREXB(New, pAddr);
}

inline u16 LL16(const volatile u16 *pAddr) 
{
      return __LDREXH((volatile u16 *)pAddr);
}

// 1 - если запись произведена
inline u16 SC16(volatile u16 *pAddr, u16 New) 
{
	return !__STREXH(New, pAddr);
}

#define LOCK(index) do {LL8(&index);
#define UNLOCK(index)  } while (!SC8(&index, 0))

#define LOCK_FAA16(index, add) { u16 i;do { i = LL16(&index) + add;
#define UNLOCK_FAA16(index) } while (!SC16(&index, i)); }
#define LOCK_FAA16ra(index, add, res) { do { res = LL16(&index) + add;
#define UNLOCK_FAA16ra(index, res) } while (!SC16(&index, res)); }

#define LOCK_FAA16r(index, res) { do { res = LL16(&index);
#define UNLOCK_FAA16r(index, add, res) } while (!SC16(&index, res + add)); }

#define LOCK_FAA16i(index, res) { do { res = LL16(&index);
#define UNLOCK_FAA16i(index, add, res) } while (!SC16(&index, res + add)); }

#define LOCKV(index, res) do {res = LL16(&index);
#define UNLOCKV(index, res)  } while (!SC16(&index, res))

#define LOCK_INCB(index)   { u8 i; do { i = LL8(&index);
#define UNLOCK_INCB(index) } while (!SC8(&index, i + 1)) }

u32 atomic_and(u32 *addr, u32 val);
u32 atomic_or(u32 *addr, u32 val);
u32 FAA(u32 *pAddr, s32 nIncr);
u16 FAA16(u16 *adr, s32 inc);
u8 CAS( volatile u32 * pAddr, u32 nExpected, u32 nNew);
u8 CAS8(volatile u8 *pAddr, u8 nExpected, u8 nNew);
u8 CAS16( volatile u16 * pAddr, u16 nExpected, u16 nNew);
u16 FAA16(u16 *adr, s32 inc);
u8 FAA8(u8 *adr, s8 inc);

inline u32 atomic_inc(u32 *pAddr)
{
	return FAA(pAddr, 1);
}

inline u16 atomic_inc16(u16 *pAddr)
{
	return FAA16(pAddr, 1);
}

inline u32 atomic_dec(u32 *pAddr)
{
	return FAA(pAddr, -1);
}

inline u16 atomic_dec16(u16 *pAddr)
{
	return FAA16(pAddr, -1);
}

inline u8 atomic_inc8(u8 *pAddr)
{
	return FAA8(pAddr, 1);
}

inline u8 atomic_dec8(u8 *pAddr)
{
	return FAA8(pAddr, -1);
}

u32 atomic_and_or(u32 *addr, u32 a, u32 o);

#ifdef __cplusplus
}
#endif
