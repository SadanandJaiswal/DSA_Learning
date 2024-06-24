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
void markParent(Node *root, unordered_map<Node *, Node *> &parent_trac, Node *target)
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

vector<int> allNodeAtk(Node *root, Node *target, int k)
{
    unordered_map<Node *, Node *> parent_track;
    markParent(root, parent_track, target);
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (curr_level++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();
            if (current->left && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]])
            {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }

    return ans;
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