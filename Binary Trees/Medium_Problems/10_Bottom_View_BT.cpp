#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<int> topView(Node* root, int &maxi){
    vector<int> ans;
    if(root==NULL) return ans;

    map<int,Node*> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        root = it.first;
        int line = it.second;
        m[line] = root;

        if(root->left) q.push({root->left,line-1});
        if(root->right) q.push({root->right,line+1});
    }

    for(auto it: m){
        ans.push_back(it.second->data);
    }

    return ans;
}
// Time Complexity: O(N)
// Space Complexity: O(N);

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}