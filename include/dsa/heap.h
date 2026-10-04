#ifndef DSA_HEAP_H
#define DSA_HEAP_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} MinHeap;

MinHeap* heap_create(size_t capacity);
void heap_free(MinHeap *h);
void heap_insert(MinHeap *h, int val);
int heap_extract_min(MinHeap *h);
void heap_sort(int *arr, size_t n);

#endif
