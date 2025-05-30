#include<bits/stdc++.h>
using namespace std;

/*
    Lower Bound: Smallest index where : arr[i]>=target
*/

int lower_bound_iterative(vector<int> &arr, int target){
    int n= arr.size();
    int low =0, high = n-1;

    int ans = n;

    while(low<=high){    
        int mid = low + (high - low)/2;

        if(arr[mid]>=target){
            ans=mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return low;
}

int lower_bound_recursive(vector<int> &arr, int low, int high, int target){
    if(low>high) return low;

    int mid = low + (high-low)/2;

    if(arr[mid]>=target){
        return lower_bound_recursive(arr, low, mid-1, target);
    }else{
        return lower_bound_recursive(arr, mid+1, high, target);
    }
}

// Time Complexity: O(logN);

int main(){
    vector<int> vec = {1, 2, 4, 4, 5, 6};
    int target = 4;

    int arr[] = {1, 2, 4, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // iterator
    auto it = lower_bound(vec.begin(), vec.end(), target);
    // auto it = lower_bound(vec.begin()+low, vec.begin()+high, target);
    int index = it = vec.begin();   

    // iterator
    auto it2 = lower_bound(arr, arr+n, target);
    // auto it2 = lower_bound(arr+low, arr+high, target);
    int index2 = it - arr;


    // insert position of target in vec
    int indexInsertTarget = lower_bound(vec.begin(), vec.end(), target) - vec.begin();

    return 0;
}