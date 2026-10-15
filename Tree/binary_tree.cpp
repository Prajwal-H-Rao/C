#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

class Node
{
public:
    Node(int value)
    {
        this->val = value;
        this->right = NULL;
        this->left = NULL;
    }
    int val;
    Node *left, *right;
};

class binary_tree
{
private:
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->val;
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (!root)
            return;
        cout << root->val;
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (!root)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val;
    }

    void countNodes(Node *root, int &count)
    {
        if (!root)
            return;
        count++;
        countNodes(root->left, count);
        countNodes(root->right, count);
    }

    void countLeafNodes(Node *root, int &count)
    {
        if (!root)
            return;
        if (root->left == NULL && root->right == NULL)
            count++;
        countLeafNodes(root->left, count);
        countLeafNodes(root->right, count);
    }

    void countHeight(Node *root, int &curHeight, int &maxHeight)
    {
        if (!root->left && !root->right)
        {
            maxHeight = curHeight > maxHeight ? curHeight : maxHeight;
            --curHeight;
            return;
        }
        if (root->left)
            countHeight(root->left, ++curHeight, maxHeight);
        if (root->right)
            countHeight(root->right, ++curHeight, maxHeight);
    }

    int countDepth(Node *root, int target)
    {
        if (!root)
            return -1;
        else if (root->val == target)
            return 1;
        int left = countDepth(root->left, target);
        if (left != -1)
            return left + 1;
        int right = countDepth(root->right, target);
        if (right != -1)
            return right + 1;
        return -1;
    }

    void sumOfAllNodes(Node *root, int &sum)
    {
        if (!root)
            return;
        sum += root->val;
        sumOfAllNodes(root->left, sum);
        sumOfAllNodes(root->right, sum);
    }

    void levelorder(Node *root)
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            cout << q.front()->val;
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }

    void maxValue(Node *root, int &max)
    {
        if (!root)
            return;
        if (root->val > max)
            max = root->val;
        maxValue(root->left, max);
        maxValue(root->right, max);
    }

    void minValue(Node *root, int &min)
    {
        if (!root)
            return;
        if (root->val < min)
            min = root->val;
        minValue(root->left, min);
        minValue(root->right, min);
    }

    void countNodesAtLevelK(Node *root, int k, int &count)
    {
        if (!root)
            return;
        if (k == 0)
        {
            count++;
            return;
        }
        countNodesAtLevelK(root->left, k - 1, count);
        countNodesAtLevelK(root->right, k - 1, count);
    }

    bool checkIfIdentical(Node *root1, Node *root2)
    {
        if (!root1 && !root2)
            return true;
        if ((!root1 && root2) || (root1 && !root2))
            return false;
        if (root1->val != root2->val)
            return false;
        return checkIfIdentical(root1->left, root2->left) && checkIfIdentical(root1->right, root2->right);
    }

    Node *createBinaryTree()
    {
        Node *root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(0);
        root->left->right = new Node(5);
        root->right->left = new Node(9);
        root->right->right = new Node(7);
        root->right->right->left = new Node(8);
        return root;
    }
    /* data */
public:
    binary_tree(/* args */);
    Node *root = createBinaryTree();
    void traverse()
    {
        cout << "Preorder" << endl;
        preorder(root);
        cout << endl;
        cout << "Postorder" << endl;
        postorder(root);
        cout << endl;
        cout << "Inorder" << endl;
        inorder(root);
        cout << endl;
        cout << "Levelorder" << endl;
        levelorder(root);
        cout << endl;
        int count = 0;
        countNodes(root, count);
        cout << "Total Nodes: " << count << endl;
        int leafCount = 0;
        countLeafNodes(root, leafCount);
        cout << "The total number of leaf nodes: " << leafCount << endl;
        int height = 0;
        int curHeight = 0;
        countHeight(root, curHeight, height);
        cout << "The height of the tree is: " << height << endl;
        int depth = countDepth(root, 5);
        cout << "The depth of the node with value 5 is: " << depth << endl;
        int max = INT_MIN;
        maxValue(root, max);
        cout << "The maximum value in the tree is: " << max << endl;
        int min = INT_MAX;
        minValue(root, min);
        cout << "The minimum value in the tree is: " << min << endl;
        int sum = 0;
        sumOfAllNodes(root, sum);
        cout << "The sum of all nodes in the tree is: " << sum << endl;
        int k = 3;
        int countAtLevelK = 0;
        countNodesAtLevelK(root, k, countAtLevelK);
        cout << "The number of nodes at level " << k << " is: " << countAtLevelK << endl;
        Node *root1 = createBinaryTree();
        Node *root2 = createBinaryTree();
        root2->right->right->left = new Node(10); // Modify one node to make the trees different
        bool identical = checkIfIdentical(root, root2);
        cout << "The two trees are identical: " << (identical ? "true" : "false") << endl;
    }
    ~binary_tree();
};

binary_tree::binary_tree(/* args */)
{
}

binary_tree::~binary_tree()
{
}

int main()
{
    binary_tree *b = new binary_tree();
    b->traverse();
    return 0;
}