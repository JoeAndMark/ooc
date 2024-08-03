#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include "new.h"

// Use zero to mark available elements of heap[].
int heap[MANY] = {0};

/**
 * @brief Generic constructor.
 * 
 * @param type [ in] : a type descriptor.
 * @param ...  [ in] : var arguments.
 * 
 * @return return a pointer to a new data item
 *         or a NULL pointer if calloc() failed.
 */
void* new(const void* type, ...) {
    // int* p = NULL;
    // 
    // // Start at the second element.
    // // End with an unavailable element.
    // for (p = heap + 1; p < heap + MANY; p++) {
    //     if (!*p) {
    //         break;
    //     }
    // }

    // *p = MANY; // MANY is an impossible value for any element.

    // return p;
    const size_t size = *(const size_t* )type;
    void* p = calloc(1, size);

    assert(p);

    return (void* )p;
}

/**
 * @brief Recycle memory created by new(), or calloc() in new().
 * @param _item [ in] : a pointer to a item created by new().
 * @return void
 */
void delete(void* _item) {
    int* item = (int* )_item;

    if (item) {
        assert(item > heap && item < heap + MANY);
        *item = 0;
    }
}

