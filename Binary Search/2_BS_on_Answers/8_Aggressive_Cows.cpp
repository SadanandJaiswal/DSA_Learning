#include <bits/stdc++.h>
using namespace std;


/*  Aggressive Cows (gfg), 1552. Magnetic Force Between Two Balls (Leetcode)

    Question: Stalls array will have position of stalls where cow can be places, you need to find the minumm distance between two cows that is maximum possible to place all the cows
    Minimum distance maximum possible: eg: cows are placed at -> 1, 2, 3, 5 here minimum dis is 1 but we can also place cows on stalls -> 1,3,5,7 here min distance is 2 and if this is maximum we can place then 2 is the maximum value for minimum distance between two cows to place all the cows

    Approach 1: Brute force
        - possible answer will be 1 to maxi-mini
        - iterate through each possible answer
        - try to fit all the cows, if not possible to place all cows stop
        - maximum of this which able to place all the cows is the answer

    Approach 2: BS on answers
        - answer range is : [1, maxi-mini]
        - apply bs on answers 
        - if mid is a posssible answer then move to higher mid value
        - if not then eliminate the right search space
*/

// Approach 1: Brute Force 
int aggressiveCows_bruteForce (vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    
    int n = stalls.size();
    int mini = stalls[0], maxi = stalls[n - 1];

    int ans = INT_MIN;

    for (int dist = 1; dist <= (maxi - mini); dist++) {
        int count = 1;
        int last = stalls[0];

        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= dist) {
                count++;
                last = stalls[i];
            }
        }

        if (count >= k) ans = dist;
        else break; // Optional optimization
    }

    return ans;
}

// Approach 2: BS on answers
bool isPossible(vector<int> &v, int k, int mid){
    int cnt = 1;
    int last = v[0];
    
    for(int i=1; i<v.size();  i++){
        if(v[i]-last>=mid){
            last = v[i];
            cnt++;
        }
    }
    
    return cnt>=k;
}

int aggressiveCows_optimal(vector<int> &stalls, int k) {

    // Write your code here
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    
    int low = 1, high = stalls[n-1] - stalls[0], ans = 0;
    
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(isPossible(stalls, k, mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
    return ans;
}
// Time Complexity: O(NlogN)


int main() {
    return 0;
}