#include <bits/stdc++.h>
using namespace std;

/*
    Question: find minimum banana koko can eat to finish all bananas in h hr
    Soluiton: as we know the range of answer : 1 to max_elm of array, we will use binary search on answer
    Approach: low = 1, high = max_elm
        for each mid calculate totalHour
        if totalHour is less than h then it could be answer
        else eliminate the right part and move to left
*/

long long totalHour(vector<int> &piles, int mid){
    long long totalH = 0;
    for(int i=0; i<piles.size(); i++){
        ans += (piles[i] + mid -1) / mid;
    }
    return ans;
}

int koko_eating_bananas(vector<int> &piles, int h){
    int low = 1, high = *max_element(piles.begin(), piles.end());

    while(low <= high){
        int mid = low + (high -low)/2;

        long long totalH = totalHour(piles, mid);

        if(totalH<=h){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return low;
}
// Time Complexity: O(n * log(max_element))

int main() {


    return 0;
}