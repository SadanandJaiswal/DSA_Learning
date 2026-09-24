#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(const string& word){
        Node* node = root;

        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch, new Node());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool checkIfPrefixExists(const string& word){
        Node* node = root;

        for(char ch : word){
            if(!node->containsKey(ch)){
                return false;
            }

            node = node->get(ch);

            if(!node->isEnd()){
                return false;
            }
        }

        return true;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.

    Trie* trie = new Trie();
    for(auto &it : a){
        trie->insert(it);
    }

    string longest = "";

    for (auto& it : a) {
        if (it.length() < longest.length())
            continue;

        if (trie->checkIfPrefixExists(it)) {
            if (it.length() > longest.length() ||
                (it.length() == longest.length() && it < longest)) {
                longest = it;
            }
        }
    }

    if(longest=="") return "None";

    return longest;
}
// Time Complexity: O(n * m), where n is the number of words and m is the average length of the words.
// Space Complexity: O(n * m), where n is the number of words and m is the average length of the words.