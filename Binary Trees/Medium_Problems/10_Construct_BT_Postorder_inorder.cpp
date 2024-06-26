#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int> &postorder, vector<int> &inorder){
    map<int,int> m; // value , index

    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]] = i;
    }
    Node* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, m); 
    return root;
}

Node* buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> &m){
    if(postStart>postEnd || inStart>inEnd) return NULL;
    Node* root = new Node(postorder[postEnd]);

    int inRoot = m[root->data];
    int numLeft = inRoot - inStart;

    root->left = buildTree(postorder, postStart, postStart+numLeft-1, inorder, inStart, inRoot-1, m);
    root->right = buildTree(postorder, postStart+numLeft, postEnd-1, inorder, inRoot+1, inEnd, m);

    return root;
}


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}