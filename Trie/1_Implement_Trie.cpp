#include<bits/stdc++.h>
using namespace std;

/*
Used for Scenerios : 
    Insert(word)
    Search(word)
    StartWith(prefix)
*/

struct Node{
    Node* links[26] = {NULL};
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;

    void clear(Node* node){
        if(node == NULL) return;
        for(int i=0; i<26; i++){
            if(node->containsKey('a'+i)){
                clear(node->get('a'+i));
            }
        }
        delete node;
    }

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        clear(root);
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            // Moves to the reference Trie
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    // Time Complexity : O(L) where L is the length of the word
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }

            // Moves to the reference Trie
            node = node->get(word[i]);
        }

        return node->isEnd();
    }
    // Time Complexity : O(L) where L is the length of the word
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }

            // Moves to the reference Trie
            node = node->get(prefix[i]);
        }

        return true;
    }
    // Time Complexity : O(L) where L is the length of the prefix
};
