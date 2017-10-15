#ifndef _XARR_COMMONS_H
#define _XARR_COMMONS_H

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

#define XARR_NEW(T) (T *)malloc(sizeof(T))

#define XARR_NEWOBJ(ptr) do { \
        ptr = XARR_NEW(xarr_obj_t); \
        memset(ptr, 0, sizeof(xarr_obj_t)); \
    } while (0)

#define XARR_NEWSTR(objptr, valptr, len) do { \
        objptr->strdata = XARR_NEW(_xarr_str_t); \
        objptr->strdata->size = len; \
        objptr->strdata->str = valptr; \
        objptr->strdata = (_xarr_str_t *)objptr->strdata->str; \
    } while (0)

#endif /* !_XARR_COMMONS_H */
