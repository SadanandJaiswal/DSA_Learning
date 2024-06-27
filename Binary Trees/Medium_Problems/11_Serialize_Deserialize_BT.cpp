#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


string serialize(Node* root){
    if(!root) return "";

    string s = "";
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr==NULL) s+="#,";
        else{
            s+=to_string(curr->data)+",";
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    cout<<s<<endl;  // to debug
    return s;
}

Node* deserialize(string data){
    if(data=="") return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        getline(s,str,',');
        if(str!="#"){
            curr->left = new Node(stoi(str));
            q.push(curr->left);
        }

        getline(s,str,',');
        if(str!="#"){
            curr->right = new Node(stoi(str));
            q.push(curr->right);
        }
    }

    return root;
}
// Time Complexity: O(N);
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