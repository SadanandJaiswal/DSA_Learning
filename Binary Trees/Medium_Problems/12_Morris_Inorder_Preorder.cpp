#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


vector<int> inorder(Node* root){
    vector<int> inorder;
    Node* curr = root;

    while(curr){
        if(!curr->left){
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            if(!prev->right){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

vector<int> preorder(Node* root){
    vector<int> preorder;
    Node* curr = root;

    while(curr){
        if(!curr->left){
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            if(!prev->right){
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }

    return preorder;
}
// Time Complexity: O(N);
// Space Complexity: O(1); if we don't consider the space for return vector

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}