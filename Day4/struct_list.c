#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

struct Node *create_node(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void print_list(struct Node *linllist)
{
    struct Node *iter = linllist;
    while (iter != NULL)
    {
        printf("%d ", (*iter).data);
        iter = iter->next;
    }
    printf("\n");
}

struct Node *append_to_head(struct Node *linkedList, struct Node *new_node)
{
    new_node->next = linkedList;
    return new_node;
}

void free_memory(struct Node **head)
{
    printf("the program executed successfully and now the memory is being deleted\n");
    struct Node *next;
    while (*head != NULL)
    {
        next = (*head)->next;
        free(*head);
        *head = next;
    }
    *head = NULL;
    next = NULL;
}

int main()
{
    struct Node *head = NULL;

    head = append_to_head(head, create_node(5));
    head = append_to_head(head, create_node(4));
    head = append_to_head(head, create_node(3));
    head = append_to_head(head, create_node(2));
    head = append_to_head(head, create_node(1));
    head = append_to_head(head, create_node(0));

    print_list(head);
    free_memory(&head);

    return 0;
}