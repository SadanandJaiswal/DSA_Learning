#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int maxDepth(Node* node){
    if(node==nullptr){
        return 0;
    }

    int l = maxDepth(node->left);
    int r = maxDepth(node->right);

    return 1 + max(l,r);
}
// Time Complexity: O(N)
// Space Complexity: O(N)

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}