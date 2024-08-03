#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "new.h"

/**
 * @brief Create and initialize an object, which is an instance of _class.
 * 
 * @param _class [ in] : a class descriptor.
 * @param ...    [ in] : var arguments.
 * 
 * @return return a pointer to a new instance of _class,
 *         or a NULL pointer if calloc() failed.
 */
void* new(const void* _class, ...) {
    const struct Class* class = (const struct Class* )_class;
    void* p = calloc(1, class->_size);

    assert(p);

    *(const struct Class** )p = class;
    
    if (class->ctor) {
        va_list ap;
        va_start(ap, _class);
        p = class->ctor(p, &ap);
        va_end(ap);
    }

    return p;
}

/**
 * @brief Recycle memory created by new(), or calloc() in new().
 * @param _item [ in] : a pointer to a item created by new().
 * @return void
 */
void delete(void* self) {
    // Check NULL pointer.
    assert(self);

    const struct Class** cp = self;

    if (self && *cp && (*cp)->dtor) {
        self = (*cp)->dtor(self);
    }

    free(self);
}

void* clone(const void* self) {
    const struct Class* const* cp = self;
    
    assert(self && *cp && (*cp)->clone);

    return (*cp)->clone(self); 
}

bool differ(const void* self, const void* b) {
    const struct Class* const * cp = self;

    assert(self && *cp && (*cp)->differ);

    return (*cp)->differ(self, b);
}

size_t size(const void* self) {
    const struct Class* const * cp = self;

    assert(self && *cp);

    return (*cp)->_size;
}

