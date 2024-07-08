#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Search for NULL in left or right, when null is find in left means val<curr->val and vise versa, insert node at leaf
Node* insertNodeBST(Node* root, int key){

    if(!root) return new Node(key);
    Node* curr = root;  // as we need to return the root
    while(true){
        if(root->data <= key){  
            if(root->right) root = root->right;
            else{
                root->right = new Node(key);
                break;
            }
        }else{
            if(root->left) root = root->left;
            else{
                root->left = new Node(key);
                break;
            }
        }
    }

    return curr;
}
// Time Complexity: O(H) 

int main()
{
    // Creating the binary search tree

    return 0;
}