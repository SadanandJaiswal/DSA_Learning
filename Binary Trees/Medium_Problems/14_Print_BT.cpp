#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


int heightBT(Node* root){
    if(!root) return 0;
    return 1 + max(heightBT(root->left), heightBT(root->right));
}

void solve(Node* root, vector<vector<string>> res, int row, int col, int h){
    if(!root) return;

    res[row][col] = to_string(root->data);

    int l = col - pow(2, h-row-1);
    int r = col + pow(2, h-row-1);

    solve(root->left, res, row+1, l, h);
    solve(root->right, res, row+1, r, h);
}

vector<vector<string>> printBT(Node* root) {
    // as we need 0 based indexing , n = h-1;
    int h = heightBT(root)-1;
    int width = pow(2, h+1)-1;

    vector<vector<string>> res(h+1, vector<string>(width, ""));

    int row = 0;
    int col = (width-1)/2;

    solve(root, res, row, col, h);

    return res;
}
// Time Complexity: O(N+N)

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}