#include<bits/stdc++.h>
using namespace std;

// Approach 1: (brute force approach)
// step 1: use recursion to get all the permutations
// step 2: sort the result vector
// step 3: return the result[k-1]
// time complexity: O(n*n!) 
// n! for total number of permutations
// n for data structure used

// Approach 2: (Optimal Approach)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact =1;
        vector<int> numbers;
        for(int i=1; i<n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k-1;
        while(true)
        {
            ans = ans + to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);

            if(numbers.size()==0)
            {
                break;
            }
            k=k%fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};

// Time Complexity: O(n*n) // n for while loop, another n for erase
// Space Complexity: O(n) // vector of size n