#include <stdlib.h>
#include <stdio.h>

void enqueue(int element, int *front, int *rear, int **queue, int size)
{
    int next_index = (*rear + 1) % size;
    if (next_index == *front && *front != 0)
    {
        printf("The queue is already full\n");
        return;
    }
    (*queue)[next_index] = element;
    *rear = next_index;
    printf("Enqueued %d into the queue and teh rear is now at %d\n", element, *rear);
    return;
}

int dequeue(int **queue, int *front, int *rear, int size)
{
    if (*rear == -1)
    {
        printf("The Queue is already empty\n");
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
        (*front) = (*front + 1) % size;
    }
    printf("Dequeued %d and the front is now at %d\n", popped, *front);
    return popped;
}

void print_queue(int *queue, int front, int rear, int size)
{
    if (rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int index = front;
    while (1)
    {
        printf("%d ", queue[index]);
        if (index == rear)
            break;
        index = (index + 1) % size;
    }
    printf("\n");
}

int main()
{
    int size = 5;
    int front = 0;
    int rear = -1;
    int *queue = malloc(size * sizeof(int));

    dequeue(&queue, &front, &rear, size);

    enqueue(10, &front, &rear, &queue, size);
    print_queue(queue, front, rear, size);
    enqueue(20, &front, &rear, &queue, size);
    print_queue(queue, front, rear, size);
    dequeue(&queue, &front, &rear, size);
    print_queue(queue, front, rear, size);
    enqueue(30, &front, &rear, &queue, size);
    print_queue(queue, front, rear, size);
    dequeue(&queue, &front, &rear, size);
    print_queue(queue, front, rear, size);

    free(queue);
    return 0;
}