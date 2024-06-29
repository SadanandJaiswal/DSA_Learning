#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* searchBST(Node* root, int key){
    if(!root || root->data == key){
        return root;
    }

    if(key<root->data) {
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}

int main()
{
    // Creating the binary search tree

    return 0;
}