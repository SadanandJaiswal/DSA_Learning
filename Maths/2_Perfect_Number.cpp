#include <bits/stdc++.h>
using namespace std;

// Perfect Number is : A positive integer that is equal to the sum of its proper positive divisors.

class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long ans = 0;

        for(int i=1; i*i<=num; i++){
            if(num%i==0){
                ans+=i;

                if(i*i!=num && i!=num/i){
                    ans+=num/i;
                }
            }
        }

        return ans-num==num;
    }
};
// Time Complexity: O(sqrt(n)), where n is the number of times we can check for divisibility.
// Space Complexity: O(1), as we are using a constant amount of space for the