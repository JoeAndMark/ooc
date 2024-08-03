#include <stdio.h>
#include <stdlib.h>

#include "new.h"
#include "object.h"
#include "set.h"

int main(void) {
    struct Set* s = (struct Set* )new(Set);
    struct Object* a = (struct Object* )add(s, new(Object));
    struct Object* b = (struct Object* )add(s, new(Object));
    struct Object* c = (struct Object* )new(Object);

    printf("1.contains(s, a) && contains(s, b):\n");
    if (contains(s, a) && contains(s, b)) {
        printf("  s contains a and b.\n");
    } else {
        printf("  s doesn't contain a and b.\n");
    }

    printf("  s = %p;\n", s);
    printf("  s->count = %ld;\n", s->count);
    printf("  a->in = %p;\n", a->in);
    printf("  a->count = %lu;\n", a->count);
    printf("  b->in = %p;\n", b->in);
    printf("  b->count = %lu;\n", b->count);

    printf("\n");

    printf("2.contains(s, c):\n");
    if (contains(s, c)) {
        printf("  s contains c.\n");
    } else {
        printf("  s doesn't contain c.\n");
    }

    printf("  s = %p;\n", s);
    printf("  s->count = %ld;\n", s->count);
    printf("  c->in = %p;\n", c->in);
    printf("  c->count = %lu;\n", c->count);

    printf("\n");

    printf("3.differ(a, add(s, a)):\n");
    if (differ(a, add(s, a))) {
        printf("  a is different from add(s, a).\n");
    } else {
        printf("  a is same to add(s, a).\n");
    }

    printf("  s = %p;\n", s);
    printf("  s->count = %ld;\n", s->count);
    printf("  a->in = %p;\n", a->in);
    printf("  a->count = %lu;\n", a->count);

    printf("\n");

    printf("4.contains(s, drop(s, a)):\n");
    if (contains(s, drop(s, a))) {
        printf("  After drop(s, a), s doesn't contain a.\n");
    } else {
        printf("  After drop(s, a), s still contains a.\n");
    }
    
    printf("  s = %p;\n", s);
    printf("  s->count = %ld;\n", s->count);
    printf("  a->in = %p;\n", a->in);
    printf("  a->count = %lu;\n", a->count);

    free((struct Set* )s);
    free((struct Object* )a);
    free((struct Object* )b);
    free((struct Object* )c);
    // delete(drop(s, b));
    // delete(drop(s, c));

    return 0;
}

