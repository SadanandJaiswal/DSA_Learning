#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        for(int i=0; i<n; i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> ans;

        int i =0;
        long long currTime = 0;

        while(i<n || !pq.empty()){
            if(pq.empty() && currTime<(long long)tasks[i][0]){
                currTime = (long long)tasks[i][0];
            }

            while(i<n && currTime>=tasks[i][0]){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            auto [processTime, index] = pq.top();
            pq.pop();

            ans.push_back(index);
            currTime+=processTime;
        }

        return ans;
    }
};
// Time Complexity : O(nlogn) + O(nlogn) ~ O(nlogn)
// Space Complexity : O(n) + O(n) ~ O(n)