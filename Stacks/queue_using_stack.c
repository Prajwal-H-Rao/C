#include <stdio.h>
#include <stdlib.h>
#define MAX_CAP 3

void push(int **stack, int *top, int element)
{
    if (*top == MAX_CAP - 1)
    {
        printf("Stack overflow, aborting push\n");
        return;
    }
    (*top)++;
    (*stack)[*top] = element;
    printf("Insrted %d into the queue\n", element);
}

int pop(int **stack, int *top)
{
    if (*top == -1)
    {
        printf("The stack is alread empty\n");
        return -1;
    }
    int popped_element = (*stack)[*top];
    (*stack)[*top] = 0;
    (*top)--;
    return popped_element;
}

void push_queue(int **stack1, int *top1, int item)
{
    if (*top1 == MAX_CAP - 1)
    {
        printf("The Queue is full\n");
        return;
    }
    (*top1)++;
    (*stack1)[*top1] = item;
    printf("Insrted into the Queue\n");
}

int pop_queue(int **stack2, int *top2, int **stack1, int *top1)
{
    if (*top2 == -1 && *top1 != -1)
    {
        while (*top1 != -1)
        {
            int popped = pop(stack1, top1);
            push(stack2, top2, popped);
        }
        printf("Popped\n");
        return pop(stack2, top2);
    }
    else if (*top2 != -1)
    {
        printf("Popped\n");
        return pop(stack2, top2);
    }
    else if (*top1 == -1 && *top2 == -1)
    {
        printf("Queue is empty nothing to dequeue\n");
        return -1;
    }
}

void print_queue(int *stack1, int top1, int *stack2, int top2)
{
    printf("Queue: ");
    for (int i = top2; i >= 0; i--)
    {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main()
{
    int *stack1 = (int *)malloc(sizeof(int) * MAX_CAP);
    int *stack2 = (int *)malloc(sizeof(int) * MAX_CAP);
    int top1 = -1;
    int top2 = -1;

    push_queue(&stack1, &top1, 10);
    print_queue(stack1, top1, stack2, top2);
    push_queue(&stack1, &top1, 20);
    print_queue(stack1, top1, stack2, top2);
    push_queue(&stack1, &top1, 30);
    print_queue(stack1, top1, stack2, top2);

    printf("Dequeued: %d\n", pop_queue(&stack2, &top2, &stack1, &top1));
    print_queue(stack1, top1, stack2, top2);
    printf("Dequeued: %d\n", pop_queue(&stack2, &top2, &stack1, &top1));
    print_queue(stack1, top1, stack2, top2);
    printf("Dequeued: %d\n", pop_queue(&stack2, &top2, &stack1, &top1));
    print_queue(stack1, top1, stack2, top2);

    return 0;
}