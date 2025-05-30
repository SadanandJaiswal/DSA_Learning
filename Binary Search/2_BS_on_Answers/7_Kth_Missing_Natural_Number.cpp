#include <bits/stdc++.h>
using namespace std;

/*
    Questoin: Sorted Array of natural number is given, find the kth missing number
    
    Approach 1: Brute Force : O(N)
        - start variable starting from 1 and missed variable to count missed number
        - if missed is equal to k then print the number in start variable
    
    Approach 2: Binary Search
        - We directly can't use binary search for this question
        - Pattern we observed, at ith index there should be i+1 number if all number are present and not missed
        - if i+1 number is not present on ith index means : arr[i] - i -1 number are missing till ith index
        - we will use binary search on this missing number
        - if missing number is less than k then eliminate the left space 
        - else eliminate the right space
        - when low<=high became false then high will piont to the missing number less than k
        - by adding the remaining missing to taht number we will get the kth missing number
        - kth missing number = low + k or high + k + 1
*/

int kth_missing_number(vector<int> &arr, int k){
    int n = arr.size();
    int low = 1, high = n-1;

    while(low<=high){
        int (mid = high + low )/2;

        int missing = arr[mid] - mid - 1;

        if(missing < k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return low + k;
    return high + 1 + k;
}
// Time Complexity: O(logN)

int main() {
    return 0;
}