#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
class Trie{
    struct Node{
        Node* links[26];
        int endCnt = 0;
        int prefixCnt = 0;

        Node(){
            for(int i=0; i<26; i++){
                links[i] = nullptr;
            }
        }
    };

    Node* root;

    void eraseHelper(Node* node, const string& word, int index){
        if(index==word.length()){
            node->prefixCnt--;
            node->endCnt--;
            return;
        }

        int ind = word[index] - 'a';
        Node* child = node->links[ind];

        eraseHelper(child, word, index+1);

        if(node!=root){
            node->prefixCnt--;
        }

        if(child->prefixCnt==0){
            delete child;
            node->links[ind] = nullptr;
        }
    }

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(char ch : word){
            if(node->links[ch-'a']==nullptr){
                node->links[ch-'a'] = new Node();
            }

            node = node->links[ch-'a'];
            node->prefixCnt++;
        }

        node->endCnt++;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;

        for(char ch : word){
            if(node->links[ch-'a']==nullptr){
                return 0;
            }

            node = node->links[ch-'a'];
        }

        return node->endCnt;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;

        for(char ch : word){
            if(node->links[ch-'a']==nullptr){
                return 0;
            }

            node = node->links[ch-'a'];
        }

        return node->prefixCnt;
    }

    void erase(string &word){
        eraseHelper(root, word, 0);
    }
};
// Time Complexity: O(L) for insert, countWordsEqualTo, countWordsStartingWith, and erase operations, where L is the length of the word.
// Space Complexity: O(N*L) where N is the number of words inserted and L is the average length of the words.


// Iterative approach
#include <bits/stdc++.h> 
class TrieIterative {
    struct Node {
        Node* links[26];
        int endCnt = 0;
        int prefixCnt = 0;

        // In-class member initialization handles setting links to nullptr 
        // in modern C++, but if your compiler is older, you can uncomment the constructor:
        Node() {
            for(int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }
    };

    Node* root;

    public:

    TrieIterative() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(node->links[ch-'a'] == nullptr) {
                node->links[ch-'a'] = new Node();
            }

            node = node->links[ch-'a'];
            node->prefixCnt++;
        }

        node->endCnt++;
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;

        for(char ch : word) {
            if(node->links[ch-'a'] == nullptr) {
                return 0;
            }

            node = node->links[ch-'a'];
        }

        return node->endCnt;
    }

    int countWordsStartingWith(string &word) {
        Node* node = root;

        for(char ch : word) {
            if(node->links[ch-'a'] == nullptr) {
                return 0;
            }

            node = node->links[ch-'a'];
        }

        return node->prefixCnt;
    }

    void erase(string &word) {
        // Optional safety check: ensure word exists before erasing
        if (countWordsEqualTo(word) == 0) return;

        Node* node = root;

        for(char ch : word) {
            node = node->links[ch-'a'];
            node->prefixCnt--;
        }

        node->endCnt--; // Decrement by 1 instead of setting to 0
    }
};
// Time Complexity: O(L) for insert, countWordsEqualTo, countWordsStartingWith, and erase operations, where L is the length of the word.