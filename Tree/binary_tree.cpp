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

    void countNodes(Node* root, int &count){
        if(!root) return;
        count++;
        countNodes(root->left, count);
        countNodes(root->right, count);
    }

    void countLeafNodes(Node* root, int &count){
        if(!root) return;
        if(root->left==NULL && root->right==NULL) count++;
        countLeafNodes(root->left,count);
        countLeafNodes(root->right,count);
    }

    void countHeight(Node* root, int &curHeight ,int &maxHeight){
        if(!root->left && !root->right){
            maxHeight=curHeight>maxHeight?curHeight:maxHeight;
            --curHeight;
            return;
        }
        countHeight(root->left,++curHeight,maxHeight);
        countHeight(root->right,++curHeight,maxHeight);
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
        int count = 0;
        countNodes(root, count);
        cout << "Total Nodes: " << count << endl;
        int leafCount = 0;
        countLeafNodes(root,leafCount);
        cout<< "The total number of leaf nodes: "<< leafCount<<endl;
        int height = 0;
        int curHeight = 0;
        countHeight(root,curHeight,height);
        cout<<"The height of the tree is: "<< height <<endl;
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