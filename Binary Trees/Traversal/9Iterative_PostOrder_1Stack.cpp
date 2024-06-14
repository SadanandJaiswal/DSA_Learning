#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

vector<int> PostOrder(Node* root){
    vector<int> ans;
    stack<Node*> s;
    Node* curr = root;
   
   while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }else{
            Node* temp = s.top()->right;
            if(temp==NULL){
                temp = s.top();
                s.pop();
                ans.push_back(temp->data);
                while(!s.empty() && temp==s.top()->right){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }else{
                curr = temp;
            }
        }
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