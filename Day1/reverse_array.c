#include <stdio.h>
#include<stdlib.h>

void reverse_array(int array[], int size)
{
    int *start = array, *end = array + size-1;
    while (start <= end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main()
{
    int *array = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        *(array + i) = i + 1;
    }
    printf("Before Reversing:\n");
    for (int i = 0; i < 5; i++)
        printf("%d", *(array + i));
    reverse_array(array, 5);
    printf("\nAfter Reversing:\n");
    for (int i = 0; i < 5; i++)
        printf("%d", *(array + i));
    printf("\n");
    return 0;
}