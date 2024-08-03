#include <assert.h>

#include "set.h"
#include "new.h"
#include "object.h"

const size_t _Set = sizeof(struct Set);
const void* Set = &_Set; // extern

/**
 * @brief Add an element to a set.
 *
 * @param _set     [ in] : add element to the set.
 * @param _element [ in] : the element to be added.
 * 
 * @return A pointer to the element added.
 * 
 * @note If the _element has already in the _set, its reference count will increment.
 */
void* add(void* _set, const void* _element) {
    // int* set = (int* )_set;
    // const int* element = (const int* )_element;

    // assert(set > heap && set < heap + MANY);
    // assert(*set == MANY);
    // assert(element > heap && element < heap + MANY);

    // if (*element == MANY) {
    //     *(int* )element = set - heap;
    // } else {
    //     assert(*element == set - heap);
    // }

    // return (void* )element;
    struct Set* set = (struct Set* )_set;
    struct Object* element = (struct Object* )_element;

    // Check NULL pointer.
    assert(set);
    assert(element);
    
    if (!element->in) {
        element->in = set;
    } else {
        assert(element->in == set);
    }

    ++element->count;
    ++set->count;

    return (void* )element;
}

/**
 * @brief Look for an element in a set.
 * 
 * @param set     [ in] : the set.
 * @param element [ in] : the element to be found.
 * 
 * @return A pointer to element if the element in the set,
 *         or a NULL pointer.
 */
void* find(const void* _set, const void* _element) {
    // const int* set = (const int* )_set;
    // const int* element = (const int* )_element;

    // assert(set > heap && set < heap + MANY);
    // assert(*set == MANY);
    // assert(element > heap && element < heap + MANY);
    // assert(*element);

    // return *element == set - heap ? (void* )element : NULL;
    const struct Object* element = _element;

    assert(_set);
    assert(element);

    return element->in == _set ? (void* )element : NULL;
}

/**
 * @brief Remove an element from a set.
 * 
 * @param _set     [ in] : the set.
 * @param _element [ in] : the element.
 * 
 * @return A pointer to the _element.
 */
void* drop(void* _set, const void* _element) {
    // int* element = (int* )find(_set, _element);

    // if (element) {
    //     *element = MANY;
    // }

    // return (void* )element;
    struct Set* set = (struct Set* )_set;
    struct Object* element = (struct Object* )find(_set, _element);

    if (element) { // The element in the set.
        
        if (--element->count == 0) {
            element->in = NULL;
        }
        
        --set->count;
    }

    return (void* )element;
}

/**
 * @brief Convert the result of find() into a boolean value.
 * 
 * @param _set     [ in] : the set.
 * @param _element [ in] : the element.
 * 
 * @return return true if the _element is in the _set, and vice versa.
 */
bool contains(const void* _set, const void* _element) {
    return find(_set, _element) != NULL;
}

/**
 * @brief Get the number of elements in the set.
 * 
 * @param _set [ in] : the set.
 * 
 * @return The value of reference count.
 */
size_t count(const void* _set) {
    const struct Set* set = (const struct Set* )_set;

    assert(set);

    return set->count;
}

