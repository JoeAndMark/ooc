#ifndef __NEW_H__
#define __NEW_H__

#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>

struct Class {
    size_t _size;
    void* (* ctor)(void* self, va_list* app);
    void* (* dtor)(void* self);
    void* (* clone)(const void* self);
    bool (* differ)(const void* self, const void* d);
};

void* new(const void* type, ...);
void delete(void* _item);

void* clone(const void* self);
bool differ(const void* self, const void* b);
size_t size(const void* self);

#endif /* __NEW_H__  */

