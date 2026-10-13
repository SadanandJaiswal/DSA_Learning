#include<bits/stdc++.h>
using namespace std;

// Every element appears three times except for one, which appears exactly once. Find that single one.

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


class SolutionBetter{
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int bitPos=0; bitPos<32; bitPos++){
            int count = 0;

            for(int num : nums){
                if(num & (1<<bitPos)){
                    count++;
                }
            }

            if(count%3!=0){
                ans |= (1<<bitPos);
            }
        }

        return ans;
    }
};
// Time Complexity: O(32*n) = O(n), where n is the number of elements in the input vector nums, as we are iterating through all 32 bits for each number.
// Space Complexity: O(1), as we are using a constant amount of space for the   


class SolutionOptimal {  // Using Sorting
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]!=nums[i+1]){
                return nums[i];
            }
        }

        return nums[nums.size()-1];
    }
};

class SolutionOptimal2 {  // Using Sorting
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i=1; i<n; i+=3){
            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
        }

        return nums[n-1];
    }
};
// Time Complexity: O(nlog(n)), where n is the number of elements in the input vector nums, due to the sorting step.
// For INT : it will be 32 bits, so the time complexity will be O(32*n) = O(n).
// Space Complexity: O(1), as we are using a constant amount of space for the


/* ***************** Why Optimal Approach is actually Optimal than Better Approach ***************** */
// Better Approach have time complexity of fixed : 32*n, while Optimal Approach have time complexity of nlogn, which in worst case goes to 32*n


class SolutionMostOptimal { // Using Bucket
public:
    // If number is not present in two then add it to one
    // If number is present in one then delete it from one and add it to two
    
    // to check if number is not present in two : ~twos, to add use xor operator
    // similarly for two 
    
    int singleNumber(vector<int>& nums){
        int ones = 0, twos = 0;
        for(int num : nums){
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }   
        return ones;
    }
};
// Time Complexity: O(n), where n is the number of elements in the input vector nums, as we are iterating through all the numbers once.
// Space Complexity: O(1), as we are using a constant amount of space for the