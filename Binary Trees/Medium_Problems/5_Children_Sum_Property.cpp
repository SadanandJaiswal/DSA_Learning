#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool isChildSum(Node* root){
    if(!root || (!root->left && !root->right)) return true;

    int sum =0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;

    if(sum==root->data){
        return isChildSum(root->left) && isChildSum(root->right);
    }

    return false;
}

// Children Sum Property: node value = left.val + right.val;
// if bt is not showing children sum property then we will convert it to follow this property
// as we are not bound to have minimum +1 operation hence we will increase the val to max possible to satisf the conditions
void convertToChildrenSum(Node* root){
    if(!root){
        return;
    }

    int child =0;
    if(root->left){
        child+= root->left->data;
    }
    if(root->right){
        child+= root->right->data;
    }

    if(child >= root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    convertToChildrenSum(root->left);
    convertToChildrenSum(root->right);

    int total = 0;
    if(root->left) total+= root->left->data;
    if(root->right) total+= root->right->data;

    // if not a leaf node
    if(root->left || root->right) root->data = total;
}
// Time Complexity: O(N);
// Space Complexity: O(H);

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}