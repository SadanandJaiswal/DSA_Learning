#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int cnt = 0;
        while(n>0){
            cnt+=n&1;
            n=n>>1;
        }
        return cnt;
    }
};
// Time Complexity: O(log(n)), where n is the maximum of start and goal.


class SolutionBetter {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int cnt = 0;
        while(n>0){
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
};
// Time Complexity: O(k), where k is the number of set bits in n (start^goal).