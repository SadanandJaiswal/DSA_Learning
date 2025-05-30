#include <bits/stdc++.h>
using namespace std;

int square_root_floor(int n){
    int low = 1, high = n;

    while(low<=high){
        long long mid = low + (high-low)/2;

        if(mid*mid>n){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return high;
}
// Time Complexity: O(logN)

int main() {
    return 0;
}