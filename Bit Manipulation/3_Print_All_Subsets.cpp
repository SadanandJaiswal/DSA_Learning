#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        for(int mask=0; mask<(1<<n); mask++){
            vector<int> temp;

            /*
            int num = mask;
            int ind = 0;
            
            while(num){
                if(num&1){
                    temp.push_back(nums[ind]);
                }
                
                num>>= 1;
                ind++;
            }
            */
            
            for(int i=0; i<n; i++){
                if(mask & (1<<i)){  // Check if the i-th bit is set in the mask
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};