#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


// Width: mo of nedes in a level between any 2 node
int widthBT(Node* root){
    if(root==NULL) return 0;
    queue<pair<Node*,unsigned long long >> q;
    q.push({root,0});
    int ans =0;

    while(!q.empty()){
        int size=q.size();
        unsigned long long  min = q.front().second;
        unsigned long long  first, last;
        for(int i=0; i<size; i++){
            int curr_id = q.front().second - min;
            root = q.front().first;
            q.pop();

            if(i==0) first = curr_id;
            if(i==size-1) last = curr_id;
            
            if(root->left) q.push({root->left, curr_id*2+1});
            if(root->right) q.push({root->right, curr_id*2+2});
        }

        ans = max(ans, int(last-first+1));
    }

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