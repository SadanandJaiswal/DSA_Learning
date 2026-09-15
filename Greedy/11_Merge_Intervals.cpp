#include<bits/stdc++.h>
using namespace std;

class SolutionNaive {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        });

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            int lastInd = ans.size()-1;

            int lastStart = ans[lastInd][0];
            int lastEnd = ans[lastInd][1];

            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(lastStart<=currStart && currStart<=lastEnd){
                ans[lastInd][1] = max(lastEnd, currEnd);
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
// Time Complexity : O(nlogn) + O(n) = O(nlogn)
// Space Complexity : O(n) for ans vector


class SolutionOptimal {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for(auto &interval : intervals){
            if(merged.empty() || merged.back()[1]<interval[0]){
                merged.push_back(interval);
            }else{
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
// Time Complexity : O(nlogn) + O(n) = O(nlogn)
// Space Complexity : O(n) for merged vector