#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BSTIterator{
    stack<Node*> s;
    public:
    BSTIterator(Node* root){
        pushAllLeft(root);
    }

    bool hasNext(){ // O(1)
        return !s.empty();
    }

    int next(){ // O(1)
        Node* temp = s.top();
        s.pop();
        pushAllLeft(temp->right);
        return temp->data;
    }

    private:
    void pushAllLeft(Node* root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
};

int main()
{
    // Creating the binary search tree

    return 0;
}