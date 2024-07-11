#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Successor
Node* inorderSuccessor(Node* root, Node* p){
    Node* successor = NULL;

    while(root){
        if(root->data <= p->data){
            root = root->right;
        }
        else{
            successor = root;
            root = root->left;
        }
    }

    return successor;
}

// Predeccessor
Node* inorderPredecossor(Node* root, Node* p){
    Node* predecessor = NULL;

    while(root){
        if(root->data >= p->data)
        {
            root = root->left;
        }else{
            predecessor = root;
            root = root->right;
        }
    }

    return predecessor;
}

// Time Complexity: O(H) -> height of the bst
// Space Complexity: O(1)

int main()
{
    // Creating the binary search tree

    return 0;
}