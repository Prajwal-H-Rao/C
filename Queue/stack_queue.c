#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int is_full(int front, int rear)
{
    return front == (rear + 1) % MAX_SIZE && rear != -1;
}

int is_empty(int rear)
{
    return rear == -1;
}

void push(int element, int *front, int *rear, int **queue)
{
    if (is_full(*front, *rear))
    {
        printf("The Stack is already full\n");
        return;
    }

    if (is_empty(*rear))
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        *rear = (*rear + 1) % MAX_SIZE;
    }

    (*queue)[*rear] = element;
    printf("Inserted the element into the stack\n");
}

int pop(int *front, int *rear, int **queue)
{
    if (is_empty(*rear))
    {
        printf("The stack is empty\n");
        return -1;
    }

    int popped = (*queue)[*front];
    (*queue)[*front] = 0;

    if (*front == *rear)
    {
        *front = 0;
        *rear = -1;
    }
    else
    {
        *front = (*front + 1) % MAX_SIZE;
    }

    return popped;
}

void print_stack(int front, int rear, int *stack)
{
    printf("Stack contents: ");

    if (rear == -1)
    {
        printf("empty");
    }
    else
    {
        int index = front;
        while (1)
        {
            printf("%d ", stack[index]);
            if (index == rear)
                break;
            index = (index + 1) % MAX_SIZE;
        }
    }

    printf("\nFront: %d, Rear: %d\n", front, rear);
}

int main()
{
    int *stack = (int *)calloc(MAX_SIZE, sizeof(int));
    int front = 0;
    int rear = -1;

    push(10, &front, &rear, &stack);
    print_stack(front, rear, stack);

    push(20, &front, &rear, &stack);
    print_stack(front, rear, stack);

    printf("Popped: %d\n", pop(&front, &rear, &stack));
    print_stack(front, rear, stack);

    push(30, &front, &rear, &stack);
    print_stack(front, rear, stack);

    printf("Popped: %d\n", pop(&front, &rear, &stack));
    print_stack(front, rear, stack);

    free(stack);
    return 0;
}