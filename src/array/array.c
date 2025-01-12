#include "array.h"

/** Initializes an array with `count` elements of length `size`.
  *
  * Params:
  * `arr`: A pointer to an `array` struct.
  * `size`: The size of each element in the array.
  * `count`: The number of elements in the array.
  * 
  * Returns: `int`
  * `ARRAY_SUCCESS` unless `arr` is invalid, the count or size is 0, or the array 
  * itself cannot be allocated, in which case `ARRAY_FAIL`. 
  */
int array_init(array* arr, unsigned long long size, unsigned int count) 
{
    if (!arr) return ARRAY_FAIL;
    
    arr->count = count;
    arr->size = size;
    arr->data = malloc(size * count);

    if (!arr->data) return ARRAY_FAIL;

    return ARRAY_SUCCESS;
}

/** Frees the array from memory.
  * 
  * Params:
  * `arr`: A pointer to an `array` struct.
  * 
  * Returns: `int`
  * `ARRAY_SUCCESS` unless `arr` is invalid or uninitialized, in which case, `ARRAY_FAIL`.
  */
int array_delete(array* arr) 
{
    if (!arr || !arr->data) return ARRAY_FAIL;
    free(arr->data);

    return ARRAY_SUCCESS;
}

/** Set the element in `arr` at `index` to `data`.
  *
  * Params:
  * `arr`: A pointer to an `array` struct.
  * `data`: A pointer to data to be inserted into the array.
  * `index`: The index at which to insert `data`.
  * 
  * Returns:
  * `ARRAY_FAIL` if `arr` is an invalid pointer or uninitialized, `data` is invalid, or 
  * `index` is out of bounds. Otherwise, `ARRAY_SUCCESS`.
  */
int array_set(array* arr, void* data, unsigned int index) 
{
    if (!arr || !arr->data || !data || index >= arr->count) return ARRAY_FAIL;

    *((char*)arr->data + index * arr->size) = *(char*)data;

    return ARRAY_SUCCESS;
}

/** Returns a pointer to the value at `index`.
  * 
  * Params:
  * `arr`: A pointer to an `array` struct.
  * `index`: The index in which to index into the array.
  * 
  * Returns: `void*`
  * 0 if `arr` is invalid, uninitialized, or index is out of bounds, 
  * otherwise, return a pointer to the data.
  */
void* array_get(array* arr, unsigned int index) 
{
    if (!arr || !arr->data || index >= arr->count) return 0;

    return (char*)arr->data + arr->size * index;
}