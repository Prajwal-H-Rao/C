#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

int *create_arrayI(int size)
{
    return (int *)malloc(size * sizeof(int));
}

int *resize_array(int *array, int *current_size)
{
    int new_size = *current_size * 2;
    *current_size = new_size;
    return (int *)realloc(array, new_size * sizeof(int));
}

void free_memory(int **array, int size)
{
    free(*array);
    *array = NULL;
}

int main()
{
    int *array = create_arrayI(2);
    int current_size = 2;

    for (int i = 0; i < 10; i++)
    {
        printf("Enter the next element\n");
        if (i > current_size - 1)
        {
            array = resize_array(array, &current_size);
            printf("The array was resized to size %d\n", current_size);
        }
        scanf("%d", &(*(array + i)));
    }

    print_array(array, 10);

    free_memory(&array, current_size);
    printf("The memory was freed\n");

    return 0;
}