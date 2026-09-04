#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach : This can be (maximum number of platform overlaping at any point of time) but this will take O(n^2) time complexity
class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 1;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                // Is train j present when train i arrives?
                if (arr[j] <= arr[i] && arr[i] <= dep[j]) {
                    cnt++;
                }
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
// Time Complexity : O(n*n)
// Space Complexity : O(1)


// Better Approach : Sort the (time, type)
class SolutionBetter {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        vector<pair<int,int>> vec;
        
        for(int i=0; i<arr.size(); i++){
            vec.push_back({arr[i], 0});
            vec.push_back({dep[i], 1});
        }
        
        sort(vec.begin(), vec.end());
        
        int ans = 0;
        int cnt = 0;
        
        for(auto [time, type] : vec){
            if(type){
                cnt--;
            }else{
                cnt++;
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};


// Optimal : Greedy Approach : Sort the arrival and departure time and use two pointer approach
class SolutionOptimal {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i=0, j=0;
        
        int cnt=0, ans=0;
        
        while(i<arr.size() && j<dep.size()){
            if(arr[i]<=dep[j]){
                cnt++;
                ans = max(ans,cnt);
                i++;
            }else{
                cnt--;
                j++;
            }
        }
        
        return ans;
    }
};
// Time Complexity : O(nlogn)
// Space Complexity : O(1)