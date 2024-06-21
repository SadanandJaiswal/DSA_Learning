#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Diameter : longest path between two node, not required to pass via root
bool isSameTree(Node* p, Node* q){
    if(p==NULL || q==NULL){
        return p==q;
    }

    return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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