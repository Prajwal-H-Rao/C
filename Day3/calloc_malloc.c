#include <stdio.h>
#include <stdlib.h>

int *create_calloc(int size)
{
    return (int *)calloc(sizeof(int), size);
}

int *create_malloc(int size)
{
    return (int *)malloc(size * sizeof(int));
}

void print_array(int *array, int size)
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
    int *array_malloc, *array_calloc;
    printf("Creating array using malloc\n");
    array_malloc = create_malloc(10);
    printf("Creating array using calloc\n");
    array_calloc = create_calloc(10);

    printf("Printing array created using malloc\n");
    print_array(array_malloc, 10);
    printf("Printing array created using calloc\n");
    print_array(array_calloc, 10);

    printf("Freeing the allocated memory to both the arrays\n");
    free_memory(&array_calloc);
    free_memory(&array_malloc);
    return 0;
}