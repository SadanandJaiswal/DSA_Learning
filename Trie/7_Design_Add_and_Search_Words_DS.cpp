/****************** Leetcode 211. Design Add and Search Words Data Structure ******************/

#include<bits/stdc++.h>
using namespace std;

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

class WordDictionary {
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

    bool dfs(Node* node, const string &word, int ind){
        if(ind==word.size()){
            return node->isEnd();
        }

        char ch = word[ind];

        if(ch!='.'){
            if(!node->containsKey(word[ind])){
                return false;
            }

            return dfs(node->get(ch), word, ind+1);
        }

        for(int i=0; i<26; i++){
            if(node->containsKey(i+'a')){
                if(dfs(node->get(i+'a'), word, ind+1)){
                    return true;
                }
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }

    ~WordDictionary(){
        clear(root);
    }
    
    void addWord(string word) {
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
    
    bool search(string word) {
        Node* node = root;
        return dfs(node, word, 0);
    }
};
// Time Complexity: O(N * L), where N is the number of words and L is the average length of the words.