#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int pop(struct Node **top, bool peek)
{
    if (*top == NULL)
        return -1;
    struct Node *cur = *top;
    int popped_number = cur->data;
    if (!peek)
    {
        *top = cur->next;
        free(cur);
    }
    return popped_number;
}

void push(struct Node **top, int elemnt){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = elemnt;
    new_node->next = *top;
    *top = new_node;
} 

void print_stack(struct Node *top)
{
    printf("Stack: ");
    while (top != NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main(){
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    push(&top, 50);
    print_stack(top);

    printf("Popped: %d\n", pop(&top, false));
    printf("Popped: %d\n", pop(&top, false));
    printf("Peek: %d\n", pop(&top, true));
    printf("Popped: %d\n", pop(&top, false));
    printf("Popped: %d\n", pop(&top, false));
    printf("Popped: %d\n", pop(&top, false));

    return 0;
}