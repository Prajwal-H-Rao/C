#include <stdio.h>
#include <stdlib.h>

int *create_array(int size)
{
    return (int *)malloc(size * sizeof(int));
}

int *resize(int *array, int *current_size)
{
    int size_new = *current_size * 2;
    *current_size = size_new;
    return (int *)realloc(array, size_new * sizeof(int));
}

void print_arrays(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

void free_memory(int **array)
{
    free(*array);
    *array = NULL;
}

int main()
{
    int current_size = 5, prev_size;
    printf("Creating a new array size of 5\n");
    int *array = create_array(current_size);
    printf("Created new array of size 5\n");
    print_arrays(array, current_size);
    printf("Initializing array with 5 values\n");
    for (int i = 0; i < current_size; i++)
    {
        *(array + i) = i + 1;
    }
    print_arrays(array, current_size);
    printf("Resizing the array\n");
    prev_size = current_size;
    array = resize(array, &current_size);
    print_arrays(array, current_size);
    for (int i = prev_size; i < current_size; i++)
    {
        *(array + i) = i + 1;
    }
    print_arrays(array, current_size);
    printf("Freeing memory\n");
    free_memory(&array);
    return 0;
}