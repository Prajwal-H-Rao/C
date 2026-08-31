#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *create_node(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->next = NULL;
    node->val = value;
    return node;
}

void print_linked_list(struct Node *head)
{
    struct Node *iter;
    iter = head;
    while (iter != NULL)
    {
        printf("%d ", iter->val);
        iter = iter->next;
    }
    printf("\n");
}

struct Node *insert_at_tail(struct Node *head, struct Node *new_tail)
{
    struct Node *last;
    last = head;
    if (last == NULL)
    {
        return new_tail;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_tail;
    return head;
}

void free_memory(struct Node *head)
{
    struct Node *prev;
    while (head != NULL)
    {
        prev = head->next;
        free(head);
        head = prev;
    }
}

int main()
{
    struct Node *head = NULL;

    head = insert_at_tail(head, create_node(10));
    head = insert_at_tail(head, create_node(20));
    head = insert_at_tail(head, create_node(30));
    head = insert_at_tail(head, create_node(40));
    head = insert_at_tail(head, create_node(50));

    print_linked_list(head);
    printf("Freeing the memory\n");
    free_memory(head);

    return 0;
}