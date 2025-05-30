#include <bits/stdc++.h>
using namespace std;

/*
    Step 1: Figure out which is the sorted part, either left or right
    Step 2: if left is sorted then min will be vec[low] and eleminate the left part, i.e low = mid+1
    Step 3: if right is sorted then min will be vec[mid] and eliminate the right aprt, i.e high = mid -1;
*/

int minimum_in_rotated_sorted_without_duplicates(vector<int> &vec){
    int low = 0, high = vec.size()-1, ans = INT32_MAX;

    while(low<=high){
        int mid = low + (high-low)/2;

        // if search space is already sorted
        if(vec[low]<=vec[high]){
            ans = min(ans, vec[low]);
            return ans;
        }

        if(vec[low]<=vec[mid]){ // left sorted
            ans = min(vec[low], ans);
            low = mid+1;
        }else{ // right sorted
            ans = min(ans, vec[mid]);
            high = mid -1;
        }   
    }
    return ans;
}

int minimum_in_rotated_sorted_with_duplicates(vector<int> &vec){
    int low = 0, high = vec.size()-1, ans = INT32_MAX;

    while(low<=high){
        int mid = low + (high-low)/2;

        // if duplicates: we will trim the array's search space
        if(vec[low]==vec[mid] && vec[mid]==vec[high]){
            low = low + 1;
            high = high -1;
            continue;
        }

        // if search space is already sorted
        if(vec[low]<=vec[high]){
            ans = min(ans, vec[low]);
            return ans;
        }

        if(vec[low]<=vec[mid]){ // left sorted
            ans = min(vec[low], ans);
            low = mid+1;
        }else{ // right sorted
            ans = min(ans, vec[mid]);
            high = mid -1;
        }   
    }
    return ans;
}

// Time Complexity: O(logN)

int main() {
    return 0;
}