#ifndef _XARR_OBJ_H
#define _XARR_OBJ_H

#include "commons.h"

typedef enum _xarr_type_t {
    XARR_INT,
    XARR_STR
} _xarr_type_t;

typedef struct _xarr_str_t {
    size_t size;
    char *str;
} _xarr_str_t;

typedef struct xarr_obj_t {
    _xarr_type_t type;
    union {
        int ndata;
        _xarr_str_t *strdata;
    };
} xarr_obj_t;

xarr_obj_t*
xarr_int2obj(int val)
{
    xarr_obj_t *new_obj;
    XARR_NEWOBJ(new_obj);
    memset(new_obj, 0, sizeof(xarr_obj_t));
    new_obj->type = XARR_INT;
    new_obj->ndata = val;
    return new_obj;
}

xarr_obj_t*
xarr_str2obj(char *ptr, int size)
{
    xarr_obj_t *new_obj;
    XARR_NEWOBJ(new_obj);
    new_obj->type = XARR_STR;
    XARR_NEWSTR(new_obj, ptr, (size_t)size);
    return new_obj;
}

xarr_obj_t*
xarr_sz2obj(char *sz)
{
    xarr_obj_t *new_obj;
    XARR_NEWOBJ(new_obj);
    char *ptr = sz;
    size_t len = 0;

    while (*ptr != '\0') {
        ++ptr;
        ++len;
#ifdef XARR_STR_LTBUFSIZ
        assert(len <= BUFSIZ);
#endif
    }

    return new_obj;
}

#define xarr_obj2int(obj) obj->ndata
#define xarr_obj2sz(obj) (char *)obj->strdata

#endif /* !_XARR_OBJ_H */
