#include <bits/stdc++.h>
using namespace std;

/*
    Question: Search Target in 2D Matrix
*/

/* 
    Approach 1: Brute force
        - Perform Leaner Search and find the target
    
    Time Complexity: O(n*m)
*/

/*
    Approach 2: Binary Search for Row
        - For Each row use Binary Search to check weather target present in the array : arr[i] or not
    
    Time Complexity: O(n*log(m))
*/

/*
    Approach 3: Binary Search
        - Use Binary Search 
        - Condiser All the row to be merged and take matrix to single array of length (n*m)
        - low = 0, high = n*m-1
        - i = mid / m, j = mid % m
        - check if mid element is equal to target -> return true
        - else more forward or backward depending on weather the element is greater than or less than the target
    
    Time Complexity: O(log(n*m))
*/
bool searchMatrix(vector<vector<int>>& arr, int target) {
    int n = arr.size(), m = arr[0].size();
    int low = 0, high = n*m-1;

    while(low<=high){
        int mid = low + (high - low)/2;

        int i = mid / m;
        int j = mid % m;

        if(arr[i][j]==target){
            return true;
        }else if(arr[i][j]>target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return false;
}
// Time Complexity : O(log(n*m))

int main() {
    return 0;
}