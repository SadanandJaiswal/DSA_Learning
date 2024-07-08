#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Recursive
Node* LCA(Node* root, Node* p, Node* q){

   if(!root) root;

    int curr = root->data;
    if(curr < p->data && curr < q->data){
        LCA(root->right, p, q);
    }
    else if(curr > p->data && curr > q->data){
        LCA(root->left, p, q);
    }
        return root;
}
// Time Complexity: O(H) 
// Space Complexity: O(N)

// Iterative
Node* LCA(Node* root, Node* p, Node* q){

   if(!root) root;

   while(true){
    int curr = root->data;
    if(curr < p->data && curr < q->data){
        root = root->right;
    }
    else if(curr > p->data && curr > q->data){
        root = root->left;
    }
    else{
        return root;
    }
   }
   return root;
}
// Time Complexity: O(H) 
// Space Complexity: O(1)

int main()
{
    // Creating the binary search tree

    return 0;
}