#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int floorBST(Node* root, int key){
    if(!root) return -1;
    int floor = -1;
    while(root){
        if(root->data == key) return root->data;

        if(root->data > key){
            root = root->left;
        }else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}
// Time Complexity: O(H) 

int main()
{
    // Creating the binary search tree

    return 0;
}