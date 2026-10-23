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


class SolutionBruteForce2 {
  public:
    vector<int> primeFactors(int n) {
        // code here
        
        if(n<=1) return {};
        
        vector<int> ans;
        
        for(int i=2; i<=n; i++){
            if(n%i==0){
                // ans.push_back()
                
                while(n%i==0){
                    ans.push_back(i);
                    n=n/i;
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


class SolutionOptimal {
  public:
    vector<int> primeFactors(int n) {
        // code here
        
        if(n<=1) return {};
        
        vector<int> ans;
        
        for(int i=2; i*i<=n; i++){  // sqrt(n)
            if(n%i==0){
                while(n%i==0){  // log2(n)
                    ans.push_back(i);
                    n=n/i;
                }
            }
        }

        // This is for the case when n is a prime number greater than 1
        // Example : n=780 -> 2, 3, 5, 13 are the prime factors of 780. But if n=13, then it will not be added to the ans vector as it is not divisible by any number less than or equal to sqrt(13). So we need to check if n is greater than 1, then we need to add it to the ans vector.
        
        if(n>1) ans.push_back(n);
        
        return ans;
    }
};
// Exact time complexity
// Time Complexity: O(sqrt(n)*log(n)), where n is the number of times we can check for divisibility.
// Space Complexity: O(1), as we are using a constant amount of space for the
