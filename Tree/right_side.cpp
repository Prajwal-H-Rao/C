#include<iostream>
#include<vector>
using namespace std;

typedef struct Node{
    int val;
    struct Node* right,*left;
} Node;

Node* createTree(int n){
    if(n<=0) return nullptr;

    vector<Node*> nodes;
    for(int i=0;i<n;i++){
        Node* node = new Node;
        node->val = i+1;
        node->left = nullptr;
        node->right = nullptr;
        nodes.push_back(node);
    }

    for(int i=0;i<n;i++){
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<n) nodes[i]->left = nodes[left];
        if(right<n) nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

class LeftView{
    private:
    vector<int> leftView(Node* root, int depth, vector<int>& answer){
        if(!root) return {};
        if(depth==answer.size()){
            answer.push_back(root->val);
        }
        leftView(root->left, depth+1, answer);
        leftView(root->right, depth+1, answer);

        return answer;
    }
    public:
    vector<int> treeLeftView(Node* root){
        vector<int> answer;
        return leftView(root, 0, answer);
    }
};



int main(){
    LeftView lv = LeftView();
    cout<<"Enter the number of nodes in the tree: ";
    int n;
    cin>>n;
    Node* root = createTree(n);
    vector<int> answer = lv.treeLeftView(root);
    cout<<"The left view of the tree is: ";
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }  
    return 0;
}