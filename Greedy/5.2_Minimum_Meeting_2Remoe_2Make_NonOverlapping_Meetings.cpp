#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, vector<int> &b){
            return a[1]<b[1];
        });

        int end = INT_MIN;

        int cnt = 0;

        for (auto &interval : intervals) {
            int start = interval[0];
            int finish = interval[1];

            if (start >= end) {
                cnt++;
                end = finish;
            }
        }

        return intervals.size()-cnt;
    }
};
// Time Complexity : O(nlogn);
// Space Complexity : O(1);


// Optimal Approach
