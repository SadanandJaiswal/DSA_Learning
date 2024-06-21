#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Diameter : longest path between two node, not required to pass via root
vector<vector<int>> zigZag(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;

    queue<Node*> q;
    q.push(root);
    bool flag = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);

        for(int i=0; i<size; i++){
            root = q.front();
            q.pop();

            int index = flag? i : (size-i-1);
            level[index] = root->data;

            if(root->left!=NULL) q.push(root->left);
            if(root->right!=NULL) q.push(root->right);
        }
        flag = !flag;
        ans.push_back(level);
    }

    return ans;
}
// Time Complexity: O(N)
// Space Complexity: O(h);

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}