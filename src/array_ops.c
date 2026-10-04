#include "dsa/array_ops.h"
#include <stdlib.h>

DynamicArray* da_create(size_t initial_capacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (!arr) return NULL;
    arr->data = malloc(sizeof(int) * initial_capacity);
    if (!arr->data) {
        free(arr);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

void da_free(DynamicArray *arr) {
    if (arr) {
        free(arr->data);
        free(arr);
    }
}

bool da_resize(DynamicArray *arr, size_t new_capacity) {
    if (!arr) return false;
    int *new_data = realloc(arr->data, sizeof(int) * new_capacity);
    if (!new_data) return false;
    arr->data = new_data;
    arr->capacity = new_capacity;
    return true;
}

bool da_insert_at(DynamicArray *arr, size_t index, int value) {
    if (!arr || index > arr->size) return false;
    if (arr->size >= arr->capacity) {
        size_t new_cap = arr->capacity == 0 ? 4 : arr->capacity * 2;
        if (!da_resize(arr, new_cap)) return false;
    }
    for (size_t i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->size++;
    return true;
}

bool da_delete_at(DynamicArray *arr, size_t index) {
    if (!arr || index >= arr->size) return false;
    for (size_t i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    return true;
}

int linear_search(const DynamicArray *arr, int target) {
    if (!arr) return -1;
    for (size_t i = 0; i < arr->size; i++) {
        if (arr->data[i] == target) return (int)i;
    }
    return -1;
}

int binary_search(const DynamicArray *arr, int target) {
    if (!arr) return -1;
    int low = 0, high = (int)arr->size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr->data[mid] == target) return mid;
        if (arr->data[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void bubble_sort(DynamicArray *arr) {
    if (!arr) return;
    for (size_t i = 0; i < arr->size; i++) {
        for (size_t j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(DynamicArray *arr) {
    if (!arr) return;
    for (size_t i = 1; i < arr->size; i++) {
        int key = arr->data[i];
        int j = (int)i - 1;
        while (j >= 0 && arr->data[j] > key) {
            arr->data[j + 1] = arr->data[j];
            j--;
        }
        arr->data[j + 1] = key;
    }
}

static int partition(DynamicArray *arr, int low, int high) {
    int pivot = arr->data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr->data[j] < pivot) {
            i++;
            int t = arr->data[i];
            arr->data[i] = arr->data[j];
            arr->data[j] = t;
        }
    }
    int t = arr->data[i + 1];
    arr->data[i + 1] = arr->data[high];
    arr->data[high] = t;
    return i + 1;
}

void quick_sort(DynamicArray *arr, int low, int high) {
    if (!arr || low >= high) return;
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
}
