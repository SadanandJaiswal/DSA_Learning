#include <bits/stdc++.h>
using namespace std;

int first(vector<int> &arr, int n, int target){
    int low = 0, high = n-1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid]==target){
            ans = mid;
            high = mid -1;
        }
        else if(arr[mid]>target){
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

int last(vector<int> &arr, int n, int target){
    int low = 0, high = n-1;
    int ans = -1;

    while(low<=high){
        int mid = low + (high -low)/2;

        if(arr[mid]==target){
            ans = mid;
            low = mid+1;
        }else if(arr[mid]>target){
            high = mid -1;
        }else{
            low = mid +1;
        }
    }

    return ans;
}

// Time Complexity: O(logN)

int main() {
    vector<int> v = {1,2,3,3,4,4};
    int target = 3;

    // number of occurance of 3:
    int f = first(v,v.size(),target);
    int l = last(v,v.size(),target);

    if(f==-1 || l==-1){
        cout<<0<<endl;
    }else{
        cout<<l-f+1;
    }

    // STL 
    int firstit = lower_bound(v.begin(), v.end(), target);
    int lastit = upper_bound(v.begin(), v.end(), target);

    if(firstit == v.end() || *firstit != target){
        cout<<0<<endl;
    }else{
        cout<<(lastit-v.begin() ) - (firstit - v.begin())<<endl;
    }

    return 0;
}