#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        
        sort(bt.begin(), bt.end());
        
        int lastExecutionEnd = 0;
        int sum = 0;
        
        for(int job : bt){
            sum+=lastExecutionEnd;
            lastExecutionEnd += job;
        }
        
        return sum/n;
    }
};
// Time Complexity : O(nlogn)
// Space Complexity : O(1)


/*
    1,2,3,4,5
    0,1,3,6,10
    aavg = 20/4 = 5
*/