#include <bits/stdc++.h>
using namespace std;


// 1. Better Approach : Using Priority Queue (Max Heap)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;

        for(char task : tasks){ // Time : O(n)
            freq[task]++;
        }   


        priority_queue<int> maxHeap;

        for(auto it : freq){    // Time : O(klogk)
            maxHeap.push(it.second);
        }

        int time = 0;

        while(!maxHeap.empty()){    // Time : O(nlogk)
            vector<int> remaining;
            int cycle = n+1;

            while(cycle>0 && !maxHeap.empty()){ // Time : O(klogk)
                int top = maxHeap.top();
                maxHeap.pop();
                if(top>1){
                    remaining.push_back(top-1);
                }
                time++;
                cycle--;
            }

            for(auto rem : remaining){  // Time : O(klogk)
                maxHeap.push(rem);
            }

            if(!maxHeap.empty() && cycle>0){
                time+=cycle;
            }
        }

        return time;
    }
};
// Time Complexity : O(nlogk) where n is the number of tasks and k is the number of unique tasks
// Space Complexity : O(k) where k is the number of unique tasks


// 2. Optimal Approach : Using Math
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        int maxFreq = 0, countMax = 0;

        for (char task : tasks) {
            freq[task]++;

            if (freq[task] > maxFreq) {
                maxFreq = freq[task];
                countMax = 1;
            } else if (freq[task] == maxFreq) {
                countMax++;
            }
        }

        return max((int)tasks.size(),
                   (maxFreq - 1) * (n + 1) + countMax);
    }
};
// Time Complexity : O(n) where n is the number of tasks