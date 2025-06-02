#include <bits/stdc++.h>
using namespace std;

/*
    Question: Find the row with maximum number of 1s
*/

// Approach 1: Brute Force
int row_with_max_ones_brute_force(vector<vector<int> & arr){
    int ans = -1;
    int maxi = INT32_MIN;

    int n = arr.size(), m = arr[0].size();

    for(int i=0; i<n; i++){
        int ones = 0;
        for(int j=0; j<m; j++){
            if(arr[i][j]==1) ones++;
        }

        if(ones>maxi){
            maxi = ones;
            ans = i;
        }
    }

    return ans;
}
// Time Complexity: O(n*m)

int row_with_max_ones_binary_search(vector<vector<int> & arr){
    int ans = -1;
    int maxi = INT32_MIN;

    int n = arr.size(), m = arr[0].size();
    
    for(int i=0; i<n; i++){
        int low = 0, high = m-1;
        while(low<=high){
            int mid = (low + high)/2;

            if(arr[i][mid]==1){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        int ones = m - low;

        if(ones>maxi){
            maxi = ones;
            ans = i;
        }
    }

    return ans;
}
// Time Complexity: O(n*logm)

// Other Approch using Binary Search

/*  Lower Bound : 1

    int lowerind = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
    int ones = m - lowerind;

*/

/*  Upper Bound  : 0

    int upperind = upper_bound(arr[i].begin(), arr[i].end(), 0) - arr[i].begin();
    int ones = m - upperind;

*/

/*
    First Occurance of 1 
*/

int main() {
    return 0;
}