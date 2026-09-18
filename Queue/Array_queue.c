#include <stdio.h>
#include <stdlib.h>

void enqueue(int **queue, int *front, int *rear, int size, int element)
{
    if (*rear == size - 1)
    {
        printf("the queue is out of space\n");
        return;
    }
    (*rear)++;
    (*queue)[*rear] = element;
}

int dequeue(int **queue, int *front, int *rear)
{
    if (*front > *rear)
    {
        printf("The queue is empty\n");
        return -1;
    }
    int de_queued = (*queue)[*front];
    (*front)++;
    return de_queued;
}

void printQueue(int *queue, int front, int rear)
{
    printf("Queue contents: ");
    if (front > rear)
    {
        printf("empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\nFront: %d\nRear: %d\n", front, rear);
}

int main()
{
    int size = 5;
    int *queue = malloc(size * sizeof(int));
    int front = 0;
    int rear = -1;

    enqueue(&queue, &front, &rear, size, 10);
    enqueue(&queue, &front, &rear, size, 20);
    printQueue(queue, front, rear);

    dequeue(&queue, &front, &rear);
    printQueue(queue, front, rear);

    dequeue(&queue, &front, &rear);
    printQueue(queue, front, rear);

    free(queue);
    return 0;
}