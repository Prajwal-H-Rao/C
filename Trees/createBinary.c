#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left, *right;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->right = NULL;
    newNode->right = NULL;
    // printf("The new node was created with the value %d\n", val);
    return newNode;
}

void preOrder(Node *root)
{
    if (!root)
        return;
    printf("%d", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d", root->val);
}

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    printf("%d", root->val);
    inOrder(root->right);
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Pre-order:\n");
    preOrder(root);
    printf("\n");
    printf("Post-order:\n");
    postOrder(root);
    printf("\n");
    printf("In-order:\n");
    inOrder(root);
    printf("\n");
    return 0;
}