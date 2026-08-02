#include<bits/stdc++.h>
using namespace std;

// Solution 1 (Brute Force Approach)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n%groupSize!=0) return false;

        sort(hand.begin(), hand.end());

        vector<int> vis (hand.size(), 0);

        for(int i=0; i<n; i++){
            if(vis[i]) continue;

            int last = hand[i];
            int cnt = 1;
            vis[i]=1;


            for(int j=i+1; j<n; j++){
                if(cnt>=groupSize) break;
                if(!vis[j] && hand[j]==last+1){
                    last = hand[j];
                    vis[j] = 1;
                    cnt++;
                }
            }

            if(cnt<groupSize) return false;
        }

        return true;
    }
};
// Time Complexity : O(n*n) where n is the number of cards in hand
// Space Complexity : O(n) where n is the number of cards in hand


// Solution 2 (Better Approach) using Min Heap
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        unordered_map<int,int> freq;

        for(int h : hand){
            freq[h]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it : freq){
            pq.push(it.first);
        }

        while(!pq.empty()){
            int start = pq.top();

            if(freq[start]==0){
                pq.pop();
                continue;
            }

            for(int i=start; i<start+groupSize; i++){
                if(freq[i]==0) return false;
                freq[i]--;
            }
        }

        return true;
    }
};
// Time Complexity : O(nlogk) where n is the number of cards in hand and k is the number of unique cards in hand
// Space Complexity : O(k) where k is the number of unique cards in hand


// Solution 3 (Optimal Approach) using Hash Map
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        map<int,int> freq;

        for(int h : hand){
            freq[h]++;
        }

        for(auto [card, cnt] : freq){
            if(cnt==0) continue;

            for(int next = card+1; next<card+groupSize; next++){
                if(freq[next]<cnt) return false;
                freq[next]-=cnt;
            }

            freq[card]=0;
        }

        return true;
    }
};
// Time Complexity : O(nlogn) where n is the number of cards in hand
// Space Complexity : O(k) where k is the number of unique cards in hand


// Solution 4 (Optimal Approach) using Sorting and Unordered Map
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        unordered_map<int,int> freq;

        for(int h : hand){
            freq[h]++;
        }

        sort(hand.begin(), hand.end());

        for(int h : hand){
            if(freq[h]==0) continue;

            for(int next = h; next<h+groupSize; next++){
                if(freq[next]==0) return false;
                freq[next]--;
            }
        }

        return true;
    }
};
// Time Complexity : O(nlogn) where n is the number of cards in hand
// Space Complexity : O(k) where k is the number of unique cards in hand