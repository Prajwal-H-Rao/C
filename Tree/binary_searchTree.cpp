#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Node
{
    int val;
    struct Node *left, *right;
    Node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
} Node;

class BinarySearchTree
{
private:
public:
    Node *insert(Node *root, int val)
    {
        if (!root)
            return new Node(val);
        if (root->val == val)
            return root;
        if (root->val > val)
        {
            root->left = insert(root->left, val);
        }
        if (root->val < val)
        {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }
    void preorder(Node *root)
    {
        if (!root)
            return;
        cout << root->val << endl;
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node *root)
    {
        if (!root)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << endl;
    }
    void levelorder(Node *root)
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curNode = q.front();
            q.pop();
            if (curNode->left)
                q.push(curNode->left);
            if (curNode->right)
                q.push(curNode->right);
            cout << curNode->val << " ";
        }
        cout << endl;
    }
};

int main()
{
    BinarySearchTree bst = BinarySearchTree();
    Node *root = nullptr;
    vector<int> values = {8, 7, 6, 5, 4, 3, 2, 1, 9};
    for (int value : values)
        root = bst.insert(root, value);
    bst.levelorder(root);
    return 0;
}