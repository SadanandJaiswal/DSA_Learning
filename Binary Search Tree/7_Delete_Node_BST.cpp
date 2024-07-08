#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Search for NULL in left or right, when null is find in left means val<curr->val and vise versa, insert node at leaf
Node* DeleteNodeBST(Node* root, int val){
    if(!root) return NULL;
    if(root->data == val){
        return Helper(root);
    }
    Node* dummy = root;
    while(root){
        if(root->data > val){
            if(root->left && root->left->data == val){
                root->left = Helper(root->left);
                break;
            }else{
                root = root->left;
            }
        }
        else{
            if(root->right && root->right->data == val){
                root->right = Helper(root->right);
                break;
            }else{
                root = root->right;
            }
        }
    }
    return dummy;
}
Node* Helper(Node* root){
    if(!root->left){
        return root->right;
    }else if(!root->right){
        return root->left;
    }
    Node* rightChild = root->right;
    Node* leftLastRight = FindLastRight(root->left); 
    leftLastRight->right = rightChild;
    return root->left;
}
Node* FindLastRight(Node* root){
    if(!root->right){
        return root;
    }
    return FindLastRight(root->right);
}
// Time Complexity: O(H) 

int main()
{
    // Creating the binary search tree

    return 0;
}