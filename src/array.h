#define ARRAY_FAIL 0
#define ARRAY_SUCCESS 1

#include "stdlib.h"

typedef struct _array
{
    unsigned long long size;
    unsigned int count;
    void* data;
} array;

int array_init(array* arr, unsigned long long size, unsigned int count);

int array_delete(array* arr);

int array_set(array* arr, void* data, unsigned int index);

int array_get(array* arr, unsigned int index);