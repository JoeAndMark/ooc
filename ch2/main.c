#include <stdio.h>

#include "mystring.h"
#include "new.h"

int main(void) {
    struct String* a = new(String, "Hello World!");
    struct String** aa = clone(a);

    struct String* b = new(String, "b");

    printf("a->text: %s\n", a->text);
    printf("size(a) == %lu\n", size(a));

    if (differ(a, b)) {
        printf("OK\n");
    }

    if (differ(a, aa)) {
        printf("differ?\n");
    }

    if (a == aa) {
        printf("clone?");
    }

    delete(a);
    a = NULL;
    delete(aa);
    aa = NULL;
    delete(b);
    b = NULL;

    return 0;
}

