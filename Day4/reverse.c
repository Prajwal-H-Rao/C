#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *create_node(int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void free_memory(struct node **head)
{
    struct node *temp;
    while (*head != NULL)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}

void print_list(struct node *head)
{
    struct node *iter = head;
    while (iter != NULL)
    {
        printf("%d ", iter->val);
        iter = iter->next;
    }
    printf("\n");
}

struct node *reverse_list(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *prev, *cur, *next;
    prev = NULL;
    cur = head;
    next = head->next;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main()
{
    struct node *head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    printf("Original list: ");
    print_list(head);

    head = reverse_list(head);

    printf("Reversed list: ");
    print_list(head);

    free_memory(&head);

    return 0;
}