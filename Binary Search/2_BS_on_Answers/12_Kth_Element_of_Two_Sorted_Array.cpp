#include <bits/stdc++.h>
using namespace std;

/*
    Same Solution as of median of two sorted array, only slight difference
    - low = max(0, k-m) : if k>n size of arr1, then if we take full array then also not able to satisfy k, i.e we take atleast k-m elm for arr1
    - high = min(k, n1) : if k<n then why to take the full arr1, isntead take only min(k, n)
*/

int kth_element(vector<int> &a, vector<int> &b, int k){
    int n = a.size(), m = b.size();
    if(n>m) return kth_element(b, a, k);

    int low = max(0, k-m), high = min(k, n);

    int left = k;

    while(low<=high){
        int mid1 = low + (high - low)/2;
        int mid2 = left - mid1;

        int l1 = INT32_MIN, l2 = INT32_MIN;
        int r1 = INT32_MAX, r2 = INT32_MAX;

        if(mid1>0) l1 = a[mid1-1];
        if(mid1<n) r1 = a[mid1];

        if(mid2>0) l2 = b[mid2-1];
        if(mid2<m) r2 = b[mid2];

        if(l1<=r2 && l2<=r1){
            return max(l1, l2);
        }else if(l1>r2){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return -1;
}
// Time Complexity: O(log(min(n,m)))

int main() {
    return 0;
}