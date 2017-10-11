#include <assert.h>
#include "xarr.h"

int
main()
{
    xarr_t *arr = xarr_new();
    xarr_del(arr);
    return 0;
}
