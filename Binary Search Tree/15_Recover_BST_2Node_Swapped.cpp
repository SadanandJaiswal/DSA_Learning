



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
// approach take pointer in inorder and traverl though tree and check if value is same as inorder[i++] if not then make it same
// TC -> O(2*N + NlogN) --> N for traversal(inorder), N for traversal in inorder and matching, NlogN for Sorting initial inorder
// SC -> O(N) --> O(N)


// Optimal Approach
// Approach 2:  
// Do inorder traversal without taking the inorder array just take three variable
// find first, mid, last, swap first last if no last then first and mid : first, last if no adjacent , fist,mid if both are adjacent
void inorder(Node* root, Node* &prev){
    if(!root) return ;

    inorder(root->left, prev);

    if(prev && (root->data < prev->data)){
        if(!first){
            first = prev;
            second = root;
        }else{
            last = root;
        }
    }

    prev = root;

    inorder(root->right, prev);
}

void recoverTree(Node* root){
    first = NULL;
    second = NULL;
    last = NULL;
    Node* prev = new Node(INT_MIN);
    inorder(root, prev);
    if(first && last) swap(first->data, last->data);
    else if(first && second) swap(first->data, second->data);
}
// Time complexity: O(N); 
// Space Complexity: O(H) ; stack height, but we can use moris inorder traversal to reduce this space

int main()
{
    // Creating the binary search tree

    return 0;
}