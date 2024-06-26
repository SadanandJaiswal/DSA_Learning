#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int> &preorder, vector<int> &inorder){
    map<int,int> m; // value , index

    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]] = i;
    }
    Node* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m); 
    return root;
}

Node* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> m){
    if(preStart>preEnd || inStart>inEnd) return NULL;
    Node* root = new Node(preorder[preStart]);

    int inRoot = m[root->data];
    int numLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart+1, preStart+numLeft, inorder, inStart, inRoot-1, m);
    root->right = buildTree(preorder, preStart+numLeft+1, preEnd, inorder, inRoot+1, inEnd, m);

    return root;
}
// Time Complexity: O(N);
// Space Complexity: O(N);


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}