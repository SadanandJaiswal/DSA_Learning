#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* lowestCommanAncestor(Node* root, Node* p, Node* q){
    if(root == NULL || root==p || root==q) return root;

    Node* left = lowestCommanAncestor(root->left, p, q);
    Node* right = lowestCommanAncestor(root->right, p, q);

    if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }
    else{
        return root;
    }
}
// Time Complexity: O(n);
// Space Complexity: O(n);


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}