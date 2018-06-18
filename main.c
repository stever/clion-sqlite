#include "lua.h"
#include "sqlite.h"

int main(int argc, char *argv[]) {
    do_lua_test();
    do_sqlite_test("test.db");
    return 0;
}
