#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Diameter : longest path between two node, not required to pass via root
vector<vector<int>> verticalTraversal(Node* root){
    map<int,map<int,multiset<int>>> m;
    queue<pair<Node*,pair<int,int>>> q;
    q.push({root,{0,0}});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int x = p.second.first, y = p.second.second;
        m[x][y].insert(root->data);

        if(root->left){
            q.push({root->left,{x-1,y+1}});
        }
        if(root->right){
            q.push({root->right,{x+1,y+1}});
        }
    }

    vector<vector<int>> ans;
    for(auto p: m){
        vector<int> col;
        for(auto l : p.second){
            col.insert(col.end(),l.second.begin(),l.second.end());
        }
        ans.push_back(col);
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