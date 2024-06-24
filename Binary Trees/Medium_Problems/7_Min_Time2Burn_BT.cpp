#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// we will use bfs
Node* getTargetNode(Node* root, int target) {
        if (!root) return NULL;
        if (root->data == target) return root;
        
        Node* left = getTargetNode(root->left, target);
        if (left) return left;
        
        return getTargetNode(root->right, target);
}

void markParent(Node *root, unordered_map<Node *, Node *> &parent_trac)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left)
        {
            parent_trac[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent_trac[root->right] = curr;
            q.push(curr->right);
        }
    }
}

int time2BurnBT(Node *root, int target)
{   
    if (!root) return 0;

    Node* targetNode = getTargetNode(root, target);
    if (!targetNode) return 0;

    unordered_map<Node *, Node *> parent_track;
    markParent(root, parent_track);

    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(targetNode);
    visited[targetNode] = true;
    int maxi = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool found = false;

        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();
            if (current->left && !visited[current->left])
            {
                found = true;
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                found = true;
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]])
            {
                found = true;
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
        if(found) maxi++;
    }

    return maxi;
}
// Time Complexity: O(N+N); n: parent_track, n:solve
// Space Complexity: O()

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
}