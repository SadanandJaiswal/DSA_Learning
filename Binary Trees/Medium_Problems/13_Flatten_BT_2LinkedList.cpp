#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


// Brute Force approach
Node* prev = NULL;
// Right Left Root traversal 
void flattenRecursive(Node* node){
    if(!node) return;

    flattenRecursive(node->right);
    flattenRecursive(node->left);

    node->right = prev;
    node->left = NULL;
    prev = node;
}

// Better Approach
void flatternStack(Node* root){
    if(root == NULL){
            return;
        }

    stack<Node*> st;
    st.push(root);
    Node* prev = NULL;

    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);

        if(!st.empty()){
            node->right = st.top();
        }
        node->left = NULL;
    }
}
// Time Complexity: O(N);


// Optimal Approach
void flatten(Node* root){
    if(!root) return;

    Node* curr = root;
    while(curr){
        if(curr->left){
            Node* pre = curr->left;
            while(pre->right) pre = pre->right;

            if(!pre){
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
        }

        curr = curr->right;
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}