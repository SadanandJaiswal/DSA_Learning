#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Approach 1 (brute force)
void inorder(Node* root, vector<int> & in){
        if(!root) return ;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
bool findTarget(Node* root, int k) {
    vector<int> in;
    inorder(root,in);
    int i=0;
    int j = in.size()-1;

    while(i<j){
        if(in[i]+in[j] == k) return true;
        else if(in[i]+in[j]>k){
            j--;
        }else{
            i++;
        }
    }
    return false;
}
// Time Complexity: O(N+N)
// Space Complexity: O(N); // for inorder

// Approach 2 (Using bstiterator)
class BSTIterator{
    stack<Node*> s;
    bool reverse = true;
    public:
    BSTIterator(Node* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){ // O(1)
        return !s.empty();
    }

    int next(){ // O(1)
        Node* temp = s.top();
        s.pop();
        if(reverse) pushAll(temp->left);
        else{
            pushAll(temp->right);
        }
        return temp->data;
    }

    private:
    void pushAll(Node* root){
        while(root){
            s.push(root);
            if(reverse) {
                root = root->right;
            }else{
                root = root->left;
            }
        }
    }
};

bool findTarget(Node* root, int k) {
    if(!root) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while(i<j){
        if(i+j == k){
            return true;
        }
        else if(i+j > k){
            j = r.next();
        }
        else{
            i = l.next();
        }
    }
    return false;
}
// Time complexity: O(N)
// Space Complexity: O(H*2);

int main()
{
    // Creating the binary search tree

    return 0;
}