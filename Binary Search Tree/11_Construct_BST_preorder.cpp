#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Recursive
Node* constructBST(vector<int> & preorder){
    int i=0;
    return solve(preorder, i, INT_MAX);
}

Node* solve(vector<int> & preorder, int i, int maxi){
    if(preorder.size() == i || preorder[i]>maxi) return NULL;
    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder, i, root->data);
    root->right = solve(preorder, i, maxi);
    return root;
}
// Time Complexity: O(3*H) // because we travel each node 3 time, root, left, right 
// Space Complexity: O(1)

int main()
{
    // Creating the binary search tree

    return 0;
}