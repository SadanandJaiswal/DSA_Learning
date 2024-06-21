#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool solve(Node* root, vector<int> &ans, int x){
    if(!root) return false;

    ans.push_back(root->data);

    if(root->data == x) return true;

    if(solve(root->left,ans,x) || solve(root->right, ans, x)) return true;

    ans.pop_back();
    return false;
}
vector<int> root2Node(Node* root){
    vector<int> ans;
    solve(root, ans, 5);
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