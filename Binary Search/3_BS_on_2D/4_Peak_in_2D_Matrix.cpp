#include <bits/stdc++.h>
using namespace std;

/*
    Peak in 2D: greater than all the adjacent element

    Approach: Binary Search
        - We will use binary search on col
        - for mid col, we will find the max element in that column -> this will ensure elm > top and elm>bottom
        - now we need to check for is elm>left and elm>right
        - if so then return the row and col of the element
        - if max element is less than the left then eliminate the right part
        - else eliminate the left part

        - As maxi is the maximum element in the columns and if left of that element is greater than this element
            - means all the element in mid -1 columns greater than max element will also be greater than all the element in the mid column
*/

vector<int> peak_in_2d_matrix(vector<vector<int>> & mat){
    int n = mat.size(), m = mat[0].size();

    int low = 0, high = m - 1;

    while(low<=high){
        int mid = low + (high - low)/2;

        int maxi = -1, row = -1, col = mid;

        for(int i=0; i<n; i++){
            int elm = mat[i][mid];
            if(elm>maxi){
                maxi = elm;
                row = i;
            }
        }

        int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;

        int elm = mat[row][col];

        if(elm>left && elm>right){
            return {row, col};
        }else if(elm<left){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return {-1, -1};
}

int main() {
    return 0;
}