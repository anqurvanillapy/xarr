#ifndef _XARR_OBJ_H
#define _XARR_OBJ_H

#include "commons.h"

#define XARR_NEWOBJ(ptr) do { \
        ptr = XARR_NEW(xarr_obj_t); \
        memset(ptr, 0, sizeof(xarr_obj_t)); \
    } while (0)

#define XARR_NEWSTR(objptr, valptr, len) do { \
        objptr->strdata = XARR_NEW(_xarr_str_t); \
        objptr->strdata->size = len; \
        objptr->strdata->str = valptr; \
        objptr->strdata->str[len] = '\0'; \
    } while (0)

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

size_t
_xarr_strlen(const char *psz)
{
    size_t len = strlen(psz);
#ifdef XARR_STR_LTBUFSIZ
    assert(len <= BUFSIZ);
    if (len > BUFSIZ) return NULL;
#endif
    return len;
}

xarr_obj_t*
xarr_str2obj(char *psz, int size)
{
    xarr_obj_t *new_obj;
    XARR_NEWOBJ(new_obj);
    new_obj->type = XARR_STR;
    XARR_NEWSTR(new_obj, psz, (size_t)size);
    return new_obj;
}

xarr_obj_t*
xarr_sz2obj(char *sz)
{
    if (*sz == '\0') return NULL;
    xarr_obj_t *new_obj;
    XARR_NEWOBJ(new_obj);
    new_obj->strdata = XARR_NEW(_xarr_str_t);
    new_obj->strdata->size = 0; // lazy bounds check
    new_obj->strdata->str = sz;
    return new_obj;
}

xarr_obj_t*
xarr_sz2obj1(char *sz)
{
    if (*sz == '\0') return NULL;
    xarr_obj_t *new_obj;
    XARR_NEWOBJ(new_obj);
    size_t len = _xarr_strlen(sz);
    XARR_NEWSTR(new_obj, sz, len);
    return new_obj;
}

#define xarr_obj2int(obj) obj->ndata

char *
xarr_obj2sz(xarr_obj_t *obj)
{
    if (obj == NULL || obj->strdata == NULL) return NULL;
    _xarr_str_t *pstr = obj->strdata;
    if (pstr->size == 0) pstr->size = _xarr_strlen(pstr->str);
    return (char *)pstr->str;
}

void
xarr_free(xarr_obj_t *obj)
{
    if (obj == NULL) return;
    if (obj->strdata != NULL) free(obj->strdata);
    free(obj);
}

#endif /* !_XARR_OBJ_H */
