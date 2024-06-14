#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<int> PostOrder(Node* node){
    vector<int> ans;
    stack<Node*> s1;
    stack<int> s2;
    s1.push(node);

    while(!s1.empty()){
        node = s1.top();
        s1.pop();
        s2.push(node->data);
        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }

    while(!s2.empty()){
        ans.push_back(s2.top());
        s2.pop();
    }

    return ans;
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