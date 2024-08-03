#ifndef __NEW_H__
#define __NEW_H__

#if ! defined  MANY || MANY < 1
#define MANY 10
#endif

#include <stdarg.h>

extern int heap[MANY];

void* new(const void* type, ...);
void delete(void* _item);

#endif /* __NEW_H__  */

