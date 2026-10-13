#include<bits/stdc++.h>
using namespace std;

class SolutionUsingSorting {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int index = 0;
        vector<int> ans;

        while(index<nums.size()){
            if(index+1<nums.size() && nums[index]!=nums[index+1]){
                ans.push_back(nums[index]);
                index++;
            }else{
                index+=2;
            }
        }

        if(ans.size()<2){
            ans.push_back(nums[nums.size()-1]);
        }

        return ans;
    }
};
// Time Complexity: O(nlog(n)), where n is the number of elements in the input vector nums, due to the sorting step.
// Space Complexity: O(1), as we are using a constant amount of space for the


class SolutionBruteForce {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }  

        vector<int> ans;

        for(auto [key,val] : mp){
            if(val==1){
                ans.push_back(key);
            }
        }

        return ans;
    }
};
// Time Complexity: O(n), where n is the number of elements in the input vector nums.
// Space Complexity: O(n), for storing the frequency of each element in the unordered_map.



/* Optimal Approach 

    We know when we do XOR fo two same number, the result is zero. So if we XOR all number in array result with store XOR of only two once occuring number
    XOR = a*b , a and b are te two numbr occuring only once in the array

    These two numbers are different, means there will be atleast one bit position where they are different. So we can find that bit position and divide the array into two groups based on that bit position.

    We will use the rightmost set bit of XOR and divide the array into two buckets and take XOR of each, 
    result : as same number will fall in same bucket and will cancel out each other because of XOR, and ends up having only the once number

    For rightmost set bit : n&n-1
    But for rightmost set bit with all other bit as zero : (n&n-1)^n

    as we are using n-1, if n = -2^31 then n-1 will overflow, thus we will be using long long for storing XOR
*/
class SolutionOptimal {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XorOfArray = 0;

        for(int num : nums){
            XorOfArray^=num;
        }

        // XorOfArray = a^b


        int rightmost = (XorOfArray & XorOfArray-1) ^ XorOfArray;
        int bucket1 = 0, bucket2 = 0;

        for(int num : nums){
            if(num&rightmost){
                bucket1^=num;
            }else{
                bucket2^=num;
            }
        }

        return {bucket1, bucket2};
    }
};
// Time Complexity: O(n), where n is the number of elements in the input vector nums, as we are iterating through the array multiple times but each iteration is linear.
// Space Complexity: O(1), as we are using a constant amount of space for the