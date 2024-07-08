#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Search for NULL in left or right, when null is find in left means val<curr->val and vise versa, insert node at leaf
int kthSmallest(Node* root, int k){

    int ans = -1;
    int count = 0;
    inorder(root, k, count, ans);
    return ans;
}
void inorder(Node* root, int k, int &count, int &ans){
    if(!root) return ;
    inorder(root->left, k, count, ans);
    count++;
    if(count==k){
        ans = root->data;
        return;
    }
    inorder(root->right, k, count, ans);
}
// Time Complexity: O(H) 

int main()
{
    // Generally it is observed that inorder of BST is always a sorted array
    // Approach, use inorder array / count -> count==k means curr->val = kth smallest
    // for kth larget use n-k == count -> ans (travel and find n)

    // Recursive Inorder
    // TC = O(N)
    // SC = O(N) // recursive stack size

     // Iterative Stack Inorder
    // TC = O(N)
    // SC = O(N) // stack size

     // Morris Inorder
    // TC = O(N)
    // SC = O(1)

    return 0;
}