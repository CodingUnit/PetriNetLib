#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void copy(void *dest, const void *src, int size);
void copy32(void *dest, const void *src, int size);
void copy32bound4(void *dest, const void *src, int size);

#ifdef __cplusplus
}
#endif
