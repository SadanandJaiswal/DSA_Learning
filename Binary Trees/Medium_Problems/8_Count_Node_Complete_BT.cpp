#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int countNode(Node* root){
    if(!root) return 0;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if(lh==rh) return (1<<lh)-1; // pow(2,lh) -1;
    return 1 + countNode(root->left) + countNode(root->right);
}

int findLeftHeight(Node* root){
    int h =0;
    while(root){
        h++;
        root = root->left;
    }
}
int findRightHeight(Node* root){
    int h =0;
    while(root){
        h++;
        root = root->right;
    }
}
// Time Complexity: O(logn)*O(logn) = O(logn^2);
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