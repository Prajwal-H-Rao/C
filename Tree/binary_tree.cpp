#include <iostream>
#include<queue>
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

    void levelorder(Node* root){
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            cout << q.front()->val;
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
    }

    Node *createBinaryTree()
    {
        Node *root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
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
    }
    ~binary_tree();
};

binary_tree::binary_tree(/* args */)
{
}

binary_tree::~binary_tree()
{
}

int main(){
    binary_tree* b = new binary_tree();
    b->traverse();
    return 0;
}