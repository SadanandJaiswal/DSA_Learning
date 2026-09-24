#include <bits/stdc++.h>
using namespace std;

static constexpr int MAXN = 1'000'005;

struct Node {
    Node* links[26];
    bool flag;

    Node() : links{}, flag(false) {}

    bool containsKey(char ch) const {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) const {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() const {
        return flag;
    }
};

class Trie {
private:
    Node pool[MAXN];
    int poolPtr = 0;
    Node* root;

    Node* createNode() {
        return &pool[poolPtr++];
    }

public:
    Trie() {
        root = createNode();
    }

    void insert(const string& word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, createNode());
            }

            node = node->get(ch);
        }

        node->setEnd();
    }

    bool checkIfPrefixExists(const string& word) const {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);

            if (!node->isEnd())
                return false;
        }

        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;

        for (const auto& word : words) {
            trie.insert(word);
        }

        string longest;

        for (const auto& word : words) {
            if (word.length() < longest.length())
                continue;

            if (trie.checkIfPrefixExists(word)) {
                if (word.length() > longest.length() ||
                    (word.length() == longest.length() &&
                     word < longest)) {
                    longest = word;
                }
            }
        }

        return longest;
    }
};
