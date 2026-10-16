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
    Node *search(Node *root, int key)
    {
        if (!root || root->val == key)
            return root;
        if (root->val > key)
        {
            return search(root->left, key);
        }
        if (root->val < key)
        {
            return search(root->right, key);
        }
        return NULL;
    }
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

    Node *findMin(Node *root)
    {
        if (root && !root->left && !root->right)
            return root;
        return findMin(root->left);
    }
    Node *findMax(Node *root)
    {
        if (root && !root->left && !root->right)
            return root;
        return findMin(root->right);
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
    void inorderPredecessor(Node *root, Node *&predecessor, int key)
    {
        if (!root)
            return;
        if (root->val == key)
        {
            if (root->left)
            {
                Node *cur = root->left;
                while (cur->right)
                {
                    cur = cur->right;
                }
                predecessor = cur;
            }
        }
        else if (root->val > key)
        {
            inorderPredecessor(root->left, predecessor, key);
        }
        else
        {
            predecessor = root;
            inorderPredecessor(root->right, predecessor, key);
        }
    }
    void inorderSuccessor(Node *root, Node *&successor, int key)
    {
        if (!root)
            return;
        if (root->val == key)
        {
            if (root->right)
            {
                Node *cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                successor = cur;
            }
        }
        if (root->val > key)
        {
            successor = root;
            inorderSuccessor(root->left, successor, key);
        }
        else
        {
            inorderSuccessor(root->right, successor, key);
        }
        return;
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
    int key;
    cout << "Enter the key you want to search for:" << endl;
    cin >> key;
    cout << "Searching tree for " << key << " " << (bst.search(root, key) ? bst.search(root, key)->val : -1) << endl;

    cout << " The smallest element is " << bst.findMin(root)->val << endl;
    cout << " The largest element is " << bst.findMax(root)->val << endl;

    Node *successor = nullptr;
    bst.inorderSuccessor(root, successor, key);
    cout << " The inorder successor is " << (successor ? successor->val : -1) << endl;

    Node *predecessor = nullptr;
    bst.inorderPredecessor(root, predecessor, key);
    cout << " The inorder predecessor is " << (predecessor ? predecessor->val : -1) << endl;

    return 0;
}