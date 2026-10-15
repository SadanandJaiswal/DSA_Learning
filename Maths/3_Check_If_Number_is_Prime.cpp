#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n==1) return false;
        
        for(int i=2; i<n; i++){
            if(n%i==0) return false;
        }
        
        return true;
    }
};
// Time Complexity: O(n), where n is the number of times we can check for divisibility.
// Space Complexity: O(1), as we are using a constant amount of space for the


// We can find the divisor of number in sqrt(n) time, so if a number have more than 2 divisor(including 1 and itself) then it is not a prime number
class SolutionOptimal {
  public:
    bool isPrime(int n) {
        // code here
        if(n==1) return false;
        
        
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        
        return true;
    }
};
// Time Complexity: O(sqrt(n)), where n is the number of times we can check for divisibility.
// Space Complexity: O(1), as we are using a constant amount of space for the