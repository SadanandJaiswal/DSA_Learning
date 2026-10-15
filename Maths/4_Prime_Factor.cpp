#include <bits/stdc++.h>
using namespace std;

// Prime Factor is : Prime numbers which are the divisor of a number.

bool isPrime(int n){
    if (n==1) return false;

    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }

    return true;
}


class SolutionBruteForce {
  public:
    vector<int> primeFac(int n) {
        vector<int> ans;
        
        for(int i=2; i<=n; i++){
            
            if(n%i==0){
                if(isPrime(i)){
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};
// Time Complexity: O(n*sqrt(n)), where n is the number of times we can check for divisibility and sqrt(n) is the time taken to check if a number is prime.
// Space Complexity: O(1), as we are using a constant amount of space for the


class SolutionBetter {
  public:
    vector<int> primeFac(int n) {
        vector<int> ans;
    
        for(int i=1; i*i<=n; i++){
    
            if(n%i==0){
                if(isPrime(i)){
                    ans.push_back(i);
                }
    
                if(i!=n/i && isPrime(n/i)){
                    ans.push_back(n/i);
                }
            }
        }
    
        return ans;
    }
};
// Time Complexity: O(sqrt(n)*sqrt(n)), where n is the number of times we can check for divisibility and sqrt(n) is the time taken to check if a number is prime.
// Space Complexity: O(1), as we are using a constant amount of space for the