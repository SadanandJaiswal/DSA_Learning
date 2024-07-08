#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Take range adn value of root should lie in the range to satisfy the condition
bool isValidated(Node* root){
    return solve(root, LONG_MIN, LONG_MAX);
}

bool solve(Node* root, long mini, long maxi){
    if(!root) return true;
    if(root->data <= mini || root->data >= maxi){
        return false;
    }
    return solve(root->left, mini, root->data) && solve(root->right, root->data, maxi);
}
// Time Complexity: O(H) 

int main()
{
    // Creating the binary search tree

    return 0;
}