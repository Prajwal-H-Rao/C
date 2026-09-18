#include <stdio.h>
#include <stdlib.h>

void push(int element, int **stack, int *top, int capacity)
{
    if (*top == capacity - 1)
    {
        printf("The stack is alread full\n");
        return;
    }
    (*top)++;
    (*stack)[*top] = element;
    printf("Insrted into teh stack\n");
}

int pop(int **stack, int *top, int emp)
{
    if (*top == emp)
    {
        printf("the stakc is already empty\n");
        return -1;
    }
    printf("Popping\n");
    int popped_element = (*stack)[*top];
    (*stack)[*top] = 0;
    (*top)--;
    return popped_element;
}

void printArray(int *stack, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int capacity1, capacity2;
    printf("Enter the sizes of the two stacks\n");
    scanf("%d %d", &capacity1, &capacity2);

    int total = capacity1 + capacity2;
    int *composite_stack = (int *)malloc(sizeof(int) * total);
    printf("The composite stack was created\n");
    printArray(composite_stack, total);
    capacity2 = capacity1 + capacity2;

    int top1 = -1, top2 = capacity1 - 1;
    push(1, &composite_stack, &top1, capacity1);
    printArray(composite_stack, total);
    push(2, &composite_stack, &top2, capacity2);
    printArray(composite_stack, total);
    push(3, &composite_stack, &top1, capacity1);
    printArray(composite_stack, total);
    push(4, &composite_stack, &top2, capacity2);
    printArray(composite_stack, total);

    pop(&composite_stack, &top1, -1);
    printArray(composite_stack, total);
    pop(&composite_stack, &top2, capacity1 - 1);
    printArray(composite_stack, total);
    pop(&composite_stack, &top1, -1);
    printArray(composite_stack, total);
    pop(&composite_stack, &top2, capacity1 - 1);
    printArray(composite_stack, total);
    return 0;
}