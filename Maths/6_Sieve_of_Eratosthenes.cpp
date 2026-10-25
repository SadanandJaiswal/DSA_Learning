#include <bits/stdc++.h>
using namespace std;

// Print all the primes upto N

class SolutionBruteForce {
  private:
    bool isPrime(int n){
        if(n==1) return false;
        
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        
        return true;
    }
    // Time Complexity : O(sqrt(n))

  public:
    vector<int> prime(int n) {
        // Code here
        
        if(n<2) return {};
        
        vector<int> primes;
        
        for(int i=2; i<=n; i++){
            if(isPrime(i)) primes.push_back(i);
        }
        
        return primes;
    }
};
// Time COmplexity : O(n*sqrt(n))


class SolutionBetter{
    public:
        vector<int> prime(int n){
            if(n<2) return {};

            vector<int> isPrime(n+1, true);

            vector<int> primes;

            for(int i=2; i<=n; i++){
                if(isPrime[i]){
                    primes.push_back(i);

                    for(int j=2*i; j<=n; j+=i){
                        isPrime[j] = false;
                    }
                }
            }

            return primes;
        }
};

/*
    Let's do a observation
    
    # Optimization 1 : 
    Inner loop is marking isPrime false in manner

    2*2		3*2		4*2		5*2		6*2		7*2
    2*3		3*3		4*3		5*3		6*3		7*3
    2*4		3*4		4*4		5*4		6*4		7*4
    2*5		3*5		4*5		5*5		6*5		7*5
    2*6		3*6		4*6		5*6		6*6		7*6
    2*7		3*7		4*7		5*7		6*7		7*7
    2*8		3*8		4*8		5*8		6*8		7*8
    2*9		3*9		4*9		5*9		6*9		7*9

    For 3 : We can obser we have already marked 3*2 so we will start with 3*3
    For 4 : We have already marked for 4*2,4*3 in 2 and 3 multiple , so will start from 4*4
    For 5 : We have already marked for 5*2,5*3,5*4, so start with 5*5

    We can observe we will be starting the inner loop from i*i instead of i*2

    # Optimization 2 : 
    If n = 30, 
    for i=6, we will start the inner loop by 36. out of bound
    for i=7, start with 49, out of bound

    Means we do not need to run the outer loop till n, instead sqrt(n)
*/

class SolutionOptimal{
    public:
        vector<int> prime(int n){
            if(n<2) return {};

            vector<bool> isPrime(n+1, true);    // O(n)

            isPrime[0]=isPrime[1] = false;

            // Mathematically Proven : O(n*log(log(n)))
            // Prime Harmonic Series
            for(int i=2; i*i<=n; i++){
                if(isPrime[i]){
                    for(long long j=i*i; j<=n; j+=i){
                        isPrime[j] = false;
                    }
                }
            }

            vector<int> primes;

            int l=2, r=n;

            // Prime in range l to r
            for(int i=l; i<=r; i++){    // O(n)
                if(isPrime[i]){
                    primes.push_back(i);
                }
            }

            return primes;
        }
};
// Time Complexity : O(n*log(logn))