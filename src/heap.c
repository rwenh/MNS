#include "dsa/heap.h"
#include <stdlib.h>

MinHeap* heap_create(size_t capacity) {
    MinHeap *h = malloc(sizeof(MinHeap));
    if (!h) return NULL;
    h->data = malloc(sizeof(int) * capacity);
    if (!h->data) {
        free(h);
        return NULL;
    }
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heap_free(MinHeap *h) {
    if (h) {
        free(h->data);
        free(h);
    }
}

static void heapify_up(MinHeap *h, int idx) {
    while (idx > 0 && h->data[(idx - 1) / 2] > h->data[idx]) {
        int parent = (idx - 1) / 2;
        int temp = h->data[parent];
        h->data[parent] = h->data[idx];
        h->data[idx] = temp;
        idx = parent;
    }
}

static void heapify_down(MinHeap *h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if ((size_t)left < h->size && h->data[left] < h->data[smallest]) {
        smallest = left;
    }
    if ((size_t)right < h->size && h->data[right] < h->data[smallest]) {
        smallest = right;
    }
    if (smallest != idx) {
        int temp = h->data[idx];
        h->data[idx] = h->data[smallest];
        h->data[smallest] = temp;
        heapify_down(h, smallest);
    }
}

void heap_insert(MinHeap *h, int val) {
    if (!h || h->size >= h->capacity) return;
    h->data[h->size] = val;
    heapify_up(h, (int)h->size);
    h->size++;
}

int heap_extract_min(MinHeap *h) {
    if (!h || h->size == 0) return -1;
    int min_val = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    if (h->size > 0) {
        heapify_down(h, 0);
    }
    return min_val;
}

void heap_sort(int *arr, size_t n) {
    if (!arr || n == 0) return;
    MinHeap *h = heap_create(n);
    if (!h) return;
    for (size_t i = 0; i < n; i++) {
        heap_insert(h, arr[i]);
    }
    for (size_t i = 0; i < n; i++) {
        arr[i] = heap_extract_min(h);
    }
    heap_free(h);
}
