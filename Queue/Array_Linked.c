#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

Node *createNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void enqueue(int value)
{
    Node *new_node = createNode(value);

    if (rear == NULL)
    {
        front = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

void printQueue()
{
    Node *current = front;

    printf("Queue: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\nFront: %d\n", front == NULL ? -1 : front->value);
    printf("Rear: %d\n", rear == NULL ? -1 : rear->value);
}

int dequeue()
{
    if (front == NULL)
    {
        printf("The queue is empty\n");
        return -1;
    }
    Node *temp = front;
    front = front->next;
    int val = temp->value;

    if (front == NULL)
        rear = NULL;

    printf("Returning %d\n", val);
    free(temp);
    return val;
}

int main()
{
    enqueue(1);
    printQueue();
    enqueue(2);
    printQueue();
    enqueue(3);
    printQueue();
    enqueue(4);
    printQueue();
    dequeue();
    printQueue();
    dequeue();
    printQueue();
    return 0;
}