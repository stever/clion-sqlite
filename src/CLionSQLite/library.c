#include "library.h"

#include <stdio.h>

void hello_library() {
    printf("Hello, World!\n");
}

void hello(const char *s)
{
    printf("Hello %s\n", s);
}

int calc_double(int x)
{
    return 2 * x;
}
