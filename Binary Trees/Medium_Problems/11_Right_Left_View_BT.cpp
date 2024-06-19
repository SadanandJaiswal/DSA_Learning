#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Diameter : longest path between two node, not required to pass via root
void RightView(Node* root, int level, vector<int> &ds){
    if(root==NULL) return;

    if(level==ds.size()){
        ds.push_back(root->data);
    }

    if(root->right){
        RightView(root->right, level+1, ds);
    }
    if(root->left){
        RightView(root->left, level+1, ds);
    }
}
// Time Complexity: O(N);
// Space Complexity: O(H);


void LeftView(Node* root, int level, vector<int> &ds){
    if(root==NULL) return;

    if(level==ds.size()){
        ds.push_back(root->data);
    }

    if(root->left){
        LeftView(root->left, level+1, ds);
    }
    if(root->right){
        LeftView(root->right, level+1, ds);
    }
}
// Time Complexity: O(N);
// Space Complexity: O(H);

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}