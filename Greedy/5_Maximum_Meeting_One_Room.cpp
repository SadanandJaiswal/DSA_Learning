#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<pair<int,int>> meetings;
        
        for(int i=0; i<s.size(); i++){
            meetings.push_back({f[i], i});
        }
        
        sort(meetings.begin(), meetings.end());
        
        int end = -1;
        
        vector<int> ans;
        
        for(auto [finish, index] : meetings){
            if(s[index]>end){
                ans.push_back(index+1);
                end = finish;
            }   
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
// Time Complexity : O(nlogn);
// Space Complexity : O(n);