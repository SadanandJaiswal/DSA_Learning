#include <bits/stdc++.h>
using namespace std;

/*
    As we know the range of answer and it is sorted, we will use binary search on answers 
*/

int func(int mid, int n){
    long long ans = 1;
    
    while(n>0){
        if(n%2==0){
            mid = mid * mid;
            n = n / 2;
        }else{
            ans = ans * mid;
            n = n - 1;
        }
    }
    
    return ans;
}
// Time Complexity: O(logM)

int nthRoot(int n, int m) {
    // Code here.
    int low = 1, high = m;
    
    while(low <= high){
        long long mid = low + (high -low)/2;
        
        if(func(mid, n)==m){
            return mid;
        }else if(func(mid, n)>m){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    
    return -1;
}
// Time Complexity: O(logM*logN)

int main() {
    return 0;
}