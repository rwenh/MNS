#ifndef DSA_ARRAY_OPS_H
#define DSA_ARRAY_OPS_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray* da_create(size_t initial_capacity);
void da_free(DynamicArray *arr);
bool da_resize(DynamicArray *arr, size_t new_capacity);
bool da_insert_at(DynamicArray *arr, size_t index, int value);
bool da_delete_at(DynamicArray *arr, size_t index);

int linear_search(const DynamicArray *arr, int target);
int binary_search(const DynamicArray *arr, int target);

void bubble_sort(DynamicArray *arr);
void insertion_sort(DynamicArray *arr);
void quick_sort(DynamicArray *arr, int low, int high);

#endif
