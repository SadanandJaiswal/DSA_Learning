#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void PreInPost1Traversal(Node* root){
    stack<pair<Node*,int>> s;
    s.push({root,1});
    vector<int> pre,in,post;
    if(root==NULL){
        return;
    }

    while(!s.empty()){
        auto it = s.top();
        s.pop();
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second = 2;
            s.push(it);

            if(it.first->left!=NULL){
                s.push({it.first->left,1});
            }
        }else if(it.second == 2){
            in.push_back(it.first->data);
            it.second = 3;
            s.push(it);

            if(it.first->right!=NULL){
                s.push({it.first->right,1});
            }
        }else{
            post.push_back(it.first->data);
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