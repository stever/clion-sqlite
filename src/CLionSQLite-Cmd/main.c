#include "sqlite.h"
#include "lua.h"
#include "openmp.h"

int main(int argc, char *argv[]) {
    do_openmp_test();
    do_lua_test();
    do_sqlite_test("test.db");
    return 0;
}
