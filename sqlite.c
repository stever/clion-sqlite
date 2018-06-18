#include "sqlite.h"

void do_sqlite_test() {
    sqlite3 *db;
    int rc = sqlite3_open("test.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_close(db);

}
