#include <stdio.h>
#include <assert.h>
#include "xarr.h"

void
test_obj_str()
{
    char sz[] = "foo";
    xarr_obj_t *str = xarr_sz2obj1(sz);
    assert(str->strdata->str == sz &&
            "string object should reference the original C string");
    assert(printf("%s\n", xarr_obj2sz(str)) == 4 &&
            "string object should be converted to a printf-able C string");
    xarr_free(str);
}

int
main()
{
    test_obj_str();
    return 0;
}
