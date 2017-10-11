#ifndef XARR_H
#define XARR_H

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define DEFAULT_BUFSIZ 4

typedef struct xarr_str_t {
    char *str;
    size_t size;
} xarr_str_t;

typedef struct _xarr_node_t {
    xarr_str_t *key;
    xarr_str_t *val;
    struct _xarr_node_t *next;
} _xarr_node_t;

typedef struct xarr_t {
    int *arr;
    _xarr_node_t **buf;
    size_t narrsize;
    size_t nbufsize;
    size_t size;
} xarr_t;

xarr_t*
xarr_new()
{
    xarr_t *xa = (xarr_t *)malloc(sizeof(xarr_t));
    memset(xa, 0, sizeof(xarr_t));
    return xa;
}

int
xarr_del(xarr_t *xa)
{
    if (xa == NULL) return 1;
    // FIXME: mem leaks.
    free(xa->arr);
    free(xa->buf);
    free(xa);
    return 1;
}

#endif
