#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool nextPermutation(vector<int> &digits){
        // find pivot
        int n = digits.size();
        int pivot = -1;

        for(int i=n-2; i>=0; i--){
            if(digits[i]<digits[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot==-1) return false;

        // next greater than pivot elemnt
        for(int i=n-1; i>pivot; i--){
            if(digits[i]>digits[pivot]){
                swap(digits[i], digits[pivot]);
                break;
            }
        }

        // reverse till pivot from right
        reverse(digits.begin()+pivot+1, digits.end());

        return true;
    }

    int nextGreaterElement(int n) {
        vector<int> digits;

        while(n){
            digits.push_back(n%10);
            n=n/10;
        }

        reverse(digits.begin(), digits.end());

        if(!nextPermutation(digits))
            return -1;

        long long nextGreater = 0;

        for(int d : digits){
            nextGreater = nextGreater*10 + d;
        }

        if(nextGreater>INT_MAX) return -1;
        return nextGreater;
    }
};