#ifndef _XARR_TBL_H
#define _XARR_TBL_H

#include "common.h"
#include "xobj.h"

#define DEFAULT_BUFSIZ 2

#define XARR_NEWBUF(ptr, T) do { \
        ptr = (T *)malloc(sizeof(T) * DEFAULT_BUFSIZ); \
        memset(ptr, 0, sizeof(T)); \
    } while (0)

typedef struct _xarr_node_t {
    _xarr_str_t *key;
    _xarr_str_t *val;
    struct _xarr_node_t *next;
} _xarr_node_t;

typedef struct xarr_t {
    int *arr;
    _xarr_node_t *buf;
    size_t narrsize;
    size_t nbufsize;
    size_t size;
} xarr_t;

xarr_t*
xarr_new()
{
    xarr_t *xa = XARR_NEW(xarr_t);
    XARR_NEWBUF(xa->arr, int);
    XARR_NEWBUF(xa->buf, _xarr_node_t);
    return xa;
}

void
xarr_delete(xarr_t *xa)
{
    if (xa == NULL) return;
    free(xa->arr);
    free(xa->buf);
    free(xa);
}

#endif /* !_XARR_TBL_H */
