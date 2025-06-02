#include <bits/stdc++.h>
using namespace std;

/*
    Approach 1: Brute Force
        - Take a 1D array of size n*m
        - Push all the elmement of matrix to 1D array
        - sort the array -> O(n*m(log(n*m)))
        - return the mid element of the sorted 1D array
*/
int median_2d_brute_force(vector<vector<int>> &matrix) {
        // code here
    vector<int> arr;
    
    int n = matrix.size(), m = matrix[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr.push_back(matrix[i][j]);
        }
    }

    sort(arr.begin(), arr.end());

    return arr[(n*m)/2];
}
// Time Complexity: O(n*m*log(n*m) + n*m)

/*
    Approach 2: Binary Search on Answer
        - Our Answer will lie between min and max element of the matrix
        - if we create a 1D array of all n*m element then media elemen will have n*m/2 element that are either equal to or less than the median element
        - we will use binary search for range: mini, maxi
        - We will check how many element in matrix are less than equal to the mid element
        - if count is > n*m/2 then that may be our answer and we will take the first occurance of that
*/
int upperBound(vector<int> & v, int target){
    int n = v.size();
    int ans = n;
    int low = 0, high = n - 1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(v[mid]>target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return ans;
}

int countElementSmallEqual(vector<vector<int>> &mat, int mid){
    int cnt = 0;
    int n = mat.size(), m = mat[0].size();
    
    for(int i=0; i<n; i++){
        // as row are sorted use binary search
        int noElementSmallEqual = upperBound(mat[i], mid);
        cnt+= noElementSmallEqual;
    }
    
    return cnt;
}

int median(vector<vector<int>> &mat, int n, int m){
    int n = mat.size(), m = mat[0].size();
    int low = INT32_MAX, high = INT32_MIN;

    for(int i=0; i<n; i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }

    int required = n*m/2;

    while(low<=high){
        int mid = low + (high - low)/2;

        int smallEqual = countElementSmallEqual(mat, mid);

        if(smallEqual>required){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return low;
}
// Time Complexity: O( log(maxi - mini) * n * log(m) )
// Time Complexity: O( log2(1e9) * n * log2(m) )

int main() {
    return 0;
}