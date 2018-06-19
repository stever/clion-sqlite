#include <stdio.h>
#include "sqlite.h"
#include "lua.h"
#include "openmp.h"
#include "library.h"

int main(int argc, char *argv[]) {
    do_openmp_test();
    do_lua_test();
    do_sqlite_test("test.db");
    hello_library();
    hello("Steve");
    int result = calc_double(3);
    printf("calc_double(3) = %d", result);
    return 0;
}
