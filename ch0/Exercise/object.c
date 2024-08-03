#include "object.h"
#include "set.h"

const size_t _Object = sizeof(struct Object);
// It can be considered as a type descriptor.
// It tells compiler we need how many memories we need for this type.
// But next time, we need manually tell compiler explicit type.
// Such as:
// struct Object ptr = (struct Object* )calloc(1, *Object);
const void* Object = &_Object; // extern

/**
 * @brief Compare two objects.
 * @param a[in] : an object.
 * @param b[in] : another object.
 * @return true if they are different, and vice versa.
 */
bool differ(const void* a, const void* b) {
    return a!= b;
}

