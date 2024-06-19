#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool isSymetric(Node *root)
{
    if (!root)
    {
        return true;
    }
    return solve(root->left, root->right);
}

bool solve(Node *l, Node *r)
{
    if (!l || !r)
    {
        return l == r;
    }

    if (l->data != r->data)
        return false;

    return solve(l->left, r->right) && solve(l->right, r->left);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}