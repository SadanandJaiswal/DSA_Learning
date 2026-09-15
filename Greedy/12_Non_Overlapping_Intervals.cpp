#include<bits/stdc++.h>
using namespace std;    

// Minimum Overlapping Intervals: Maximum meeting can be done in a room such that no two meetings overlap
// Maximum Overlapping Intervals : Minimum number of platforms required such that no two trains overlap


class SolutionOptimal {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });

        int lastEnd = INT_MIN;
        int removed = 0;

        for(auto &interval : intervals){
            if(interval[0]<lastEnd){
                removed++;
            }else{
                lastEnd = interval[1];
            }
        }
        
        return removed;
    }
};
// Time Complexity : O(nlogn) + O(n) = O(nlogn)
// Space Complexity : O(1)