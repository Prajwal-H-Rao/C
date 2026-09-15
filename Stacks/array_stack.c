#include <stdio.h>
#include <stdlib.h>

int pop(int array[], int *top)
{
    if (*top == -1)
        return -1;
    else
    {
        int element = array[*top];
        *top -= 1;
        return element;
    }
}

int peek(int array[], int top)
{
    if (top == -1)
        return -1;
    else
        return array[top];
}

void push(int *array, int size, int *top, int element)
{
    if (*top == size - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top += 1;
    array[*top] = element;
    return;
}

int main()
{
    int stack[5];
    int top = -1;
    int size = sizeof(stack) / sizeof(stack[0]);
    int result;

    printf("create stack[5]: top = %d\n", top);

    printf("push(stack, %d, &top, 10) -> ", size);
    push(stack, size, &top, 10);
    printf("top = %d\n", top);

    printf("push(stack, %d, &top, 20) -> ", size);
    push(stack, size, &top, 20);
    printf("top = %d\n", top);

    result = peek(stack, top);
    printf("peek(stack, top) -> %d\n", result);

    result = pop(stack, &top);
    if (result == -1)
        printf("pop(stack, &top) -> Stack is empty; top = %d\n", top);
    else
        printf("pop(stack, &top) -> %d; top = %d\n", result, top);

    result = pop(stack, &top);
    if (result == -1)
        printf("pop(stack, &top) -> Stack is empty; top = %d\n", top);
    else
        printf("pop(stack, &top) -> %d; top = %d\n", result, top);

    result = pop(stack, &top);
    if (result == -1)
        printf("pop(stack, &top) -> Stack is empty; top = %d\n", top);
    else
        printf("pop(stack, &top) -> %d; top = %d\n", result, top);

    return 0;
}