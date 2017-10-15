#ifndef _XARR_H
#define _XARR_H

#include "commons.h"
#include "xobj.h"

#define DEFAULT_BUFSIZ 2

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
    xarr_t *xa = (xarr_t *)malloc(sizeof(xarr_t));
    xa->arr = (int *)malloc(sizeof(int) * DEFAULT_BUFSIZ);
    xa->buf = (_xarr_node_t *)malloc(sizeof(_xarr_node_t) * DEFAULT_BUFSIZ);
    memset(xa->arr, 0, sizeof(int) * DEFAULT_BUFSIZ);
    memset(xa->buf, 0, sizeof(_xarr_node_t) * DEFAULT_BUFSIZ);
    return xa;
}

int
xarr_del(xarr_t *xa)
{
    if (xa == NULL) return 1;
    free(xa->arr);
    free(xa->buf);
    free(xa);
    return 1;
}

#endif /* !_XARR_H */
