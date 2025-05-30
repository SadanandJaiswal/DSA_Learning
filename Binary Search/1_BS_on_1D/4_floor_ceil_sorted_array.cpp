#include <bits/stdc++.h>
using namespace std;

/*
    Floor: Largest elm in array, where arr[i]<=target
    Ceil: Smallest elm in array, where arr[i]>=target
*/

int floor(vector<int> &arr, int target){
    int n = arr.size();
    int low=0, high = n-1;

    int ans = -1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]<=target){
            ans = arr[mid];
            low = mid+1;
        }else{
            high  = mid -1;
        }
    }

    return ans;
}

int ceil(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high -low )/2;

        if(arr[mid]>=target){
            ans = arr[mid];
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
}

int main() {
    return 0;
}