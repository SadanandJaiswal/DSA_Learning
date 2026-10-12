#include<bits/stdc++.h>
using namespace std;

class SolutionBruteForce {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        for(auto it : mp){
            if(it.second==1)
                return it.first;
        }

        return -1;
    }
};
// Time Complexity: O(n), where n is the number of elements in the input vector nums.
// Space Complexity: O(n), for storing the frequency of each element in the unordered_map.  


class SolutionOptimal {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int num : nums){
            ans ^= num;
        }

        return ans;
    }
};
// Time Complexity: O(n), where n is the number of elements in the input vector nums.
// Space Complexity: O(1), as we are using a constant amount of space for the