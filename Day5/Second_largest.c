#include <stdio.h>

void printSecondMax(int arry[], int size)
{
    int max1;
    int max2;

    max1 = (arry[0] > arry[1]) ? arry[0] : arry[1];
    max2 = (arry[0] < arry[1]) ? arry[0] : arry[1];

    for (int i = 2; i < size; i++)
    {
        if (arry[i] > max1)
        {
            max2 = max1;
            max1 = arry[i];
        }
        else if (arry[i] > max2)
        {
            max2 = arry[i];
        }
    }

    printf("The largest element is %d and the 2nd largest element is %d\n", max1, max2);
}

int main()
{
    int array[6] = {1, 2, 4, 3, 43, 2};
    printSecondMax(array, 6);
    return 0;
}