#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
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
    int min = INT_MIN, max = INT_MAX;
    int kthLargest(Node *root, int &count, int k)
    {
        if (!root)
            return -1;
        int right = kthLargest(root->right, count, k);
        if (right != -1)
            return right;
        count++;
        if (count == k)
            return root->val;
        int left = kthLargest(root->left, count, k);
        return left;
    }
    int ktheSmallest(Node *root, int &count, int k)
    {
        if (!root)
            return -1;
        int left = ktheSmallest(root->left, count, k);
        if (left != -1)
            return left;

        count++;
        if (count == k)
            return root->val;
        int right = ktheSmallest(root->right, count, k);
        return right;
    }
    bool verifyBST(Node *root, int min, int max)
    {
        if (!root)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return verifyBST(root->left, min, root->val) && verifyBST(root->right, root->val, max);
    }
    Node *deleteNodeWithChild(Node *root, int key)
    {
        if (!root)
            return root;
        if (root->val > key)
        {
            root->left = deleteNodeWithChild(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNodeWithChild(root->right, key);
        }
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (!root->left && root->right)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->left && !root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *successor = NULL;
                inorderSuccessor(root, successor, root->val);
                successor->left = root->left;
                delete root;
                return successor;
            }
        }
        return root;
    }
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
        cout << root->val << " ";
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
    Node *deleteLeafNode(Node *root)
    {
        if (!root)
            return root;
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        root->left = deleteLeafNode(root->left);
        root->right = deleteLeafNode(root->right);
        return root;
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
    vector<int> values1 = {8, 1, 2, 3};
    vector<int> values2 = {8, 2, 1, 0};
    vector<int> values3 = {8, 2, 9, 1, 3, -1, 10, -1, -1, -1, 7, -1, -1, 6, 11};

    for (int value : values3)
        if (value != -1)
        {
            root = bst.insert(root, value);
        }
    bst.levelorder(root);
    int count = 0;
    cout << "3rd smallest element is " << bst.ktheSmallest(root, count, 3) << endl;
    count = 0;
    cout << "3rd largest element is " << bst.kthLargest(root, count, 3) << endl;
    int key;
    cout << "Enter the key you want to search for:" << endl;
    cin >> key;
    cout << "Searching tree for " << key << " " << (bst.search(root, key) ? bst.search(root, key)->val : -1) << endl;

    // cout << " The smallest element is " << bst.findMin(root)->val << endl;
    // cout << " The largest element is " << bst.findMax(root)->val << endl;

    Node *successor = nullptr;
    bst.inorderSuccessor(root, successor, key);
    cout << " The inorder successor is " << (successor ? successor->val : -1) << endl;

    Node *predecessor = nullptr;
    bst.inorderPredecessor(root, predecessor, key);
    cout << " The inorder predecessor is " << (predecessor ? predecessor->val : -1) << endl;
    bst.inorder(root);
    cout << endl;
    // bst.deleteLeafNode(root);
    // bst.inorder(root);
    // cout << endl;
    cout << "Deleting a node" << endl;
    bst.deleteNodeWithChild(root, key);
    bst.inorder(root);
    cout << endl;
    cout << " The tree is BST: " << (bst.verifyBST(root, bst.min, bst.max) ? "yes" : "no") << endl;

    return 0;
}