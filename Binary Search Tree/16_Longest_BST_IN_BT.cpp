



#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Inorder traversall will be not sorted in this case, 
// correct the sorting and travel

Node* first;
Node* second;
Node* last;
Node* prev;


// Approach 1: Brute Force
// using validate BST concept, check for every node weather subtree is bst or not O(n)*O(N)
// travel through that subtree to find the number of node O(n)
// Time Complexity: O(n*n + n)



// Optimal Approach
// take three variable maxnode, minnode, maxsize
// for each node check if its greater than the left.maxnode and less than right.minnide
// if bst fails then return (intmin, inmax, 0)
class NodeValue{
    public:
        int maxNode, minNode, maxSize;
        NodeValue(int maxi, int mini, int size){
            this->minNode = mini;
            this->maxNode = maxi;
            this->maxSize = size;
        }
};

NodeValue solve(Node* root){
    if(!root){
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    auto left = solve(root->left);
    auto right = solve(root->right);

    if(left.maxNode < root->data && root->data < right.minNode){
        return NodeValue(max(root->data, right.maxNode), min(root->data, left.minNode), left.maxSize + right.maxSize +1);
    }

    return NodeValue(INT_MAX, INT_MIN, max(right.maxSize, left.maxSize));
}
int largetBST(Node* root){
    return solve(root).maxSize;
}
// Time Complexity: O(N);
// Space Complexity: O(1)

int main()
{
    // Creating the binary search tree

    return 0;
}