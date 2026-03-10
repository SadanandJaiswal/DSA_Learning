#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        int n = nums2.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top()<nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        vector<int> ans;

        for(int num : nums1){
            if(mp.find(num)==mp.end()){
                ans.push_back(-1);
            }else{
                ans.push_back(mp[num]);
            }
        }

        return ans;
    }
};