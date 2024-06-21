#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node*  root){
    return !root->left && !root->right;
}

void addLeftBoundary(Node* root, vector<int> &res){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void addRightBoundary(Node* root, vector<int> &res){
    Node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i=temp.size()-1; i>=0; --i){
        res.push_back(temp[i]);
    }
}

void addLeafNode(Node* root, vector<int> &res){
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if(root->left){
        addLeafNode(root->left,res);
    }
    if(root->right){
        addLeafNode(root->right,res);
    }
}

// Diameter : longest path between two node, not required to pass via root
vector<int> boundayTraversal(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    if(!isLeaf(root)){
        ans.push_back(root->data);
    }

    addLeftBoundary(root,ans);
    addLeafNode(root,ans);
    addRightBoundary(root,ans);

    return ans;
}
// Time Complexity: O(3*N)
// Space Complexity: O(h);

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}