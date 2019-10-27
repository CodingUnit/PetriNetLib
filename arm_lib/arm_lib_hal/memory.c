#include "lib_incl.h"
#include "memory.h"

void copy(void *dest, const void *src, int size)
{
	copy32bound4(dest, src, size);
	int copied = size & ~3;
	u8 *source = (u8 *)src + copied;
	u8 *dst = (u8 *)dest + copied;
	for (; copied < size; copied++)
	{
		*(u8 *)dst++ = *(u8 *)source++;
	}
}


void copy32(void *dest, const void *src, int size)
{
  u32 *source = (u32 *)src;
  u32 *dst = (u32 *)dest;
  for (; size > 0; size -= 4)
  {
    *dst++ = *source++;
  }
}

void copy32bound4(void *dest, const void *src, int size)
{
  u32 *source = (u32 *)src;
  u32 *dst = (u32 *)dest;
  for (; size >= 4; size -= 4)
  {
    *dst++ = *source++;
  }
}
