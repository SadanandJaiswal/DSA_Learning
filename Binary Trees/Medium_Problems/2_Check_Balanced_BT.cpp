#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int CheckBalancedBT(Node* node){
    if(node==NULL){
        return 0;
    }
    
    int l = CheckBalancedBT(node->left);
    if(l==-1){
        return -1;
    }

    int r = CheckBalancedBT(node->right);
    if(r==-1){
        return -1;
    }
    
    if(abs(l-r)>1) return -1;

    return 1 + max(l,r);
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