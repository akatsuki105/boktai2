#ifndef __INCLUDE_MALLOC_H__
#define __INCLUDE_MALLOC_H__

#include "gba/gba.h"

void* Malloc(size_t bytesize);
void Free(void* p);

#endif  // __INCLUDE_MALLOC_H__
