#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


// Min elm in BST Recursive 
int minBSTRecursive(Node* root){
    if(!root) return -1;
    if(root->left) return root->data;
    return minBSTRecursive(root->left);
}

// Min Elm in BST Iterative
int minBSTIterative(Node* root){
    if(!root) return -1;
    while(root){
        if(root->left) root = root->left;
        else return root->data;
    }
    return -1;
}

// Max elm in BST Recursive 
int maxBSTRecursive(Node* root){
    if(!root) return -1;
    if(root->right) return root->data;
    return maxBSTRecursive(root->right);
}

// Max Elm in BST Iterative
int maxBSTIterative(Node* root){
    if(!root) return -1;
    while(root){
        if(root->right) root = root->right;
        else return root->data;
    }
    return -1;
}

int main()
{
    // Creating the binary search tree

    return 0;
}