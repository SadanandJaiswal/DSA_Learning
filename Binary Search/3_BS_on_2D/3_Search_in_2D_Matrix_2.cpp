#include <bits/stdc++.h>
using namespace std;

/*
    Question: Search Target in 2D Matrix
    - Rows are sorted from left to righ
    - Columns are sorted from top to bottom
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
bool searchMatrix_Better_Approach(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i=0; i<n; i++){
        bool ans = binary_search(matrix[i].begin(), matrix[i].end(), target);
        if(ans) return true;
    }
    return false;
}

/*
    Approach 3: Binary Search
        - Use Binary Search Technique
        - We have observed that if we start with the top-right elm of matrix then we see
        - on same columns all elm below that are bigger 
        - on left in same row all elm are smaller 
    
    Time Complexity: O(n+m)
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m-1;

    while(row<n && col>=0){
        int elm = matrix[row][col];
        if(elm==target){
            return true;
        }else if(elm>target){
            col--;
        }else{
            row++;
        }
    }

    return false;
}


int main() {
    return 0;
}