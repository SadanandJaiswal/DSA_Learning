#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void Inorder(Node* root){
    stack<Node*> s;
    while(true){
        if(root != NULL){
            s.push(root);
            root = root->left;
        }else{
            if(!s.empty()) break;
            root = s.top();
            s.pop();
            cout<<root->data<<" ";
            root = root->right;
        }
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