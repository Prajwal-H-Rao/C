#include <stdio.h>
#include <stdlib.h>

void enqueue(int element, int **queue, int *front, int *rear, int size)
{
    int next_index = (*rear + 1) % (size);
    if (next_index == *front && (*queue)[*front] != -1)
    {
        printf("The queue is full\n");
        return;
    }
    (*queue)[next_index] = element;
    *rear = next_index;
    printf("Inserted %d into the Queueu and the rear is now at %d\n", element, *rear);
}

int dequeue(int **queue, int *front, int *rear, int size)
{
    if (*front == *rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int element = (*queue)[*front];
    (*queue)[*front] = -1;
    (*front) = (*front + 1) % (size);
    printf("Removing %d from the queueu\n", element);
    return element;
}

void print_queue(int *queue, int front, int rear, int size)
{
    printf("Front: %d, Rear: %d\nQueue: ", front, rear);
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int qfront(int *queue, int front)
{
    if (queue[front] == -1)
    {
        return -1;
    }
    return queue[front];
}

int main()
{
    int size = 6;
    int *queue = malloc(size * sizeof(int));
    int front = 0;
    int rear = size - 1;

    if (queue == NULL)
    {
        return 1;
    }

    for (int i = 0; i < size - 1; i++)
    {
        queue[i] = -1;
    }

    enqueue(10, &queue, &front, &rear, size);
    print_queue(queue, front, rear, size);
    enqueue(20, &queue, &front, &rear, size);
    print_queue(queue, front, rear, size);
    enqueue(30, &queue, &front, &rear, size);
    print_queue(queue, front, rear, size);
    enqueue(40, &queue, &front, &rear, size);
    print_queue(queue, front, rear, size);
    enqueue(50, &queue, &front, &rear, size);
    print_queue(queue, front, rear, size);

    printf("Front of the queue %d\n", qfront(queue, front));

    dequeue(&queue, &front, &rear, size);
    print_queue(queue, front, rear, size);
    printf("Front of the queue %d\n", qfront(queue, front));

    dequeue(&queue, &front, &rear, size);
    print_queue(queue, front, rear, size);

    free(queue);
    return 0;
}