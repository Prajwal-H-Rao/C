#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    return node;
}

void free_memory(struct Node **node)
{
    free(*node);
    *node = NULL;
}

struct Node *deleteNode(struct Node *head, int key)
{
    struct Node *cur = head, *prev = NULL;
    if (head == NULL)
        return head;
    if (head->next == NULL && head->val == key)
    {
        free_memory(&head);
        head = NULL;
        return head;
    }
    if (prev == NULL && head->val == key)
    {
        prev = head;
        head = head->next;
        free_memory(&prev);
        return head;
    }
    while (cur != NULL)
    {
        if (cur->val == key)
        {
            prev->next = cur->next;
            free_memory(&cur);
            return head;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

void print_list(struct Node *head)
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeLinkedList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free_memory(&temp);
    }
}

int main()
{
    struct Node *head = NULL;

    for (int i = 1; i <= 5; i++)
    {
        struct Node *newNode = createNode(i);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    printf("Before deleting node with value 3:\n");
    print_list(head);

    head = deleteNode(head, 3);

    printf("After deleting node with value 3:\n");
    print_list(head);

    freeLinkedList(head);

    printf("\nMemory freed successfully!\n");
    return 0;
}