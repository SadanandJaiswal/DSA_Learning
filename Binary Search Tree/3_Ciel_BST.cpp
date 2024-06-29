#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int cielBST(Node* root, int key){
    if(!root) return -1;
    int ciel = -1;

    while(root){
        if(root->data == key) return root->data;

        if(root->data < key){
            root = root->right;
        }else{
            ciel = root->data;
            root = root->left;
        }
    }

    return ciel;
}
// Time Complexity: O(H) 

int main()
{
    // Creating the binary search tree

    return 0;
}