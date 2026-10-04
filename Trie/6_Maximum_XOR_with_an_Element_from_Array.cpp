#include<bits/stdc++.h>
using namespace std;

struct Node{
private:
    Node* links[2];
public:
    Node(){
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsKey(int bit){
        return links[bit]!=nullptr;
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;

        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxNum = 0;

        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<tuple<int, int, int>> tp;

        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0];
            int m = queries[i][1];

            tp.push_back({m, x, i});
        }

        sort(tp.begin(), tp.end());

        Trie trie;
        vector<int> ans(queries.size());

        int j = 0;

        for (auto [m, x, i] : tp) {

            while (j < nums.size() && nums[j] <= m) {
                trie.insert(nums[j]);
                j++;
            }

            if (j == 0) {
                ans[i] = -1;
            } else {
                ans[i] = trie.getMax(x);
            }
        }

        return ans;
    }
};
// Time Complexity: O(NlogN + QlogQ + 32*(N+Q)) ~ O((N+Q)log(N+Q))