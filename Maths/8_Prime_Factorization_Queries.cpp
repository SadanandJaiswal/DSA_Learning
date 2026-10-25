#include <bits/stdc++.h>
using namespace std;

// Question : Prime Factors of Numbers in Query
class solutionBruteForce{
private:
    vector<int> primeFactor(int n){
        if(n<2) return {};

        vector<int> pf;

        for(int i=2; i<=n/i; i++){  // O(sqrt(N))
            while(n%i==0){
                pf.push_back(i);
                n/=i;
            }
        }

        if(n>1) pf.push_back(n);

        return pf;
    }

public:
    vector<vector<int>> primeFactorQueries(vector<int> queries){
        vector<vector<int>> ans;

        for(int num : queries){     // O(Q*sqrt(N))
            ans.push_back(primeFactor(num));
        }

        return ans;
    }
};
// Time Complexity : O(Q*sqrt(N))
// Space Complexity : O(Q*sqrt(N))


/*
    Lets Observe
    Prime Factor of : 16 is (2,2,2,2) 
    Prime FActor of : 15 is (3,5)

    we can observe number is divided by prime number, and it is smallest prime number dividing that number.
    If we can store values optimally, for a number which is the smallest prime number then we can optimize this.

    Using Sieve, we can checked is a number prime, also we can check which is the smallest prime factor for that number
*/
class SolutionOptimal {
public:
    vector<vector<int>> primeFactorQueries(vector<int> queries){
        if(queries.empty()) return {};

        int maxNum = 0;

        for(int num : queries){     // O(Q)
            maxNum = max(maxNum, num);
        }

        if(maxNum<2){
            return vector<vector<int>>(queries.size());
        }

        vector<int> smallestPrimeFactor(maxNum+1);

        for(int i=1; i<=maxNum; i++){   // O(N)
            smallestPrimeFactor[i] = i;
        }

        // if smallestPrimeFactor[i]=i remain then it a prime
        smallestPrimeFactor[0] = 0;
        smallestPrimeFactor[1] = 0;

        for(int i=2; i<=maxNum/i; i++){     // O(N*loglog(N))
            if(smallestPrimeFactor[i]==i){
                for(long long j=1LL*i*i; j<=maxNum; j+=i){
                    if(smallestPrimeFactor[j]==j){
                        smallestPrimeFactor[j] = i;
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for(int num : queries){    // O(Q*log2(N))
            if(num<2){
                ans.push_back({});
                continue;
            }

            vector<int> pf;
            
            while(num>1){   // O(log2(N))
                int smallestpf = smallestPrimeFactor[num];
                pf.push_back(smallestpf);
                num/= smallestpf;
            }

            ans.push_back(pf);
        }


        return ans;
    }
};
// Time Complexity : O(Q) + O(N) + O(N*loglog(N)) + O(Q*log2(N))
// Space Complexity : O(N)
