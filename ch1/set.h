#ifndef __SET_H__
#define __SET_H__

#include <stddef.h>
#include <stdbool.h>

struct Set {
    // count keeps track of the number of elements in a set.
    size_t count;
};

extern const void* Set;

void* add(void* _set, const void* _element);
void* find(const void* _set, const void* _element);
void* drop(void* _set, const void* _element);
bool contains(const void* _set, const void* _element);
size_t count(const void* _set);

#endif /* __SET_H__ */

