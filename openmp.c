#include "openmp.h"
#include "string_utilities.h"

static int wc(char *docname){
    char *doc = string_from_file(docname);
    if (!doc) return 0;
    char *delimiters = " `~!@#$%^&*()_-+={[]}|\\;:\",<>./?\n";
    ok_array *words = ok_array_new(doc, delimiters);
    if (!words) return 0;
    double out= words->length;
    ok_array_free(words);
    return out;
}

void do_openmp_test() {

}
