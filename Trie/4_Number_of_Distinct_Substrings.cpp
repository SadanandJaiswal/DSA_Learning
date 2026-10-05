#include<bits/stdc++.h>
using namespace std;

// Brute Force Solution (using Set)
class Solution {
public:
    int countSubs(string& s) {
        unordered_set<string> substrings;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                substrings.insert(s.substr(i, j - i));
            }
        }

        return substrings.size();
    }
};
// Time Complexity: O(N^3), where N is the length of the string s. In the worst case, we may need to generate all substrings of s, which takes O(N^2) time, and inserting each substring into the set takes O(N) time.



// Optimal Solution (using Trie)
struct Node {
    Node* links[26] = {nullptr};
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    int insert(const string& s, int start) {
        Node* node = root;
        int newNodes = 0;

        for (int i = start; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (!node->links[idx]) {
                node->links[idx] = new Node();
                newNodes++;
            }

            node = node->links[idx];
        }

        return newNodes;
    }
};

class Solution {
public:
    int countSubs(string& s) {
        Trie trie;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            ans += trie.insert(s, i);
        }

        return ans;
    }
};
// Time Complexity: O(N^2), where N is the length of the string s. In the worst case, we may need to insert all substrings of s into the Trie, which takes O(N^2) time.

