#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <stdbool.h>
#include <stddef.h>

struct Object {
    // count records how many times this element has been added to the set pointed by in.
    size_t count;
    // in is a pointer to the set which the element belongs to.
    struct Set* in;
};

extern const void* Object;

bool differ(const void* a, const void* b);

#endif /* __OBJECT_H__  */

