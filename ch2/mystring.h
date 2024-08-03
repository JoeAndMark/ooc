#ifndef __MYSTRING_H__
#define __MYSTRING_H__

struct String {
    const void* class; // Must be first.
    char* text;
};

extern const void* String;

#endif /* __MYSTRING_H__  */

