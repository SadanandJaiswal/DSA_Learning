#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Diameter : longest path between two node, not required to pass via root
int maxPathSum(Node* root, int &maxi){
    if(root==NULL) return 0;

    int l = max(0,maxPathSum(root->left,maxi));
    int r = max(0,maxPathSum(root->right,maxi));

    maxi = max(maxi, l + r + root->data);
    return root->data + max(l,r);
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