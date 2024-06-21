#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void solve(Node* root, vector<vector<int>> &ans, vector<int> &path){
    if(!root){
        return;
    }

    path.push_back(root->data);
    if(!root->left && !root->right){
        ans.push_back(path);
        path.pop_back();
        return;
    }else{
        solve(root->left, ans, path);
        solve(root->right, ans, path);
    }

    path.pop_back();
}
vector<vector<int>> root2Leaf(Node* root){
    vector<vector<int>> ans;
    vector<int> path;
    solve(root, ans, path);
    return ans;
}
// Time Complexity: O(n);
// Space Complexity: O(n);


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}