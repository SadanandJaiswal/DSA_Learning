#include <bits/stdc++.h>
using namespace std;

int isPossibleToMakeBouquets(vector<int> &v, int m, int k, int mid){
    int n = v.size();

    int cnt = 0, noOfBouquetsMade = 0;

    for(int i=0; i<n; i++){
        if(v[i]<=mid){
            cnt++;
        }else{
            noOfBouquetsMade += cnt/k;
            cnt = 0;
        }
    }

    // important: make sure to add this as we may skip this in for loop
    noOfBouquetsMade+= cnt/k;

    return noOfBouquetsMade>=m;
}

int minimum_days_to_make_m_bouquets(vector<int> &bloomDay, int m, int k){

    if((long long)m*k > bloomDay.size()) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    // int ans = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(isPossibleToMakeBouquets(bloomDay, m, k, mid)){
            // ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    // return ans;
    return low;
}
// Time Complexity: O(N * log(max_element-min_element))

int main() {
    return 0;
}