#include <bits/stdc++.h>
using namespace std;

// Question : Given Queries of range (L,R), Count prime in range

class SolutionBruteForce {
private:
    bool isPrime(int n){
        if(n<2) return false;

        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }

        return true;
    }
public:
    vector<int> countPrimeInRange(vector<vector<int>> queries){
        vector<int> ans;

        for(auto query : queries){
            int l = query[0];
            int r = query[1];

            int cnt = 0;

            for(int i=l; i<=r; i++){
                if(isPrime(i)){
                    cnt++;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
// Time Complexity : O(Q)*O(R-L+1)*O(sqrt(R-L+1))
// Considering average length to be N : O(Q)*(N+sqrt(N)) 
// Auxiliary Space : O(1), excluding the input and output.
// Output Space : O(Q)


// Using Sieve
class SolutionBetter {
private:
    vector<bool> getPrimesTillMax(){
        long long n = INT32_MAX;

        vector<bool> prime(n+1, true);

        prime[0]=prime[1] = false;

        for(int i=2; i<=n/i; i++){
            if(prime[i]){
                for(long long j=i*i; j<=n; j+=i){
                    prime[j] = false;
                }
            }
        }

        return prime;
    }

public:
    vector<int> countPrimeInRange(vector<vector<int>> queries){
        if(queries.empty()) return {};

        vector<bool> prime = getPrimesTillMax();    // O(N);

        vector<int> ans;

        for(const auto& query : queries){
            int l = query[0];
            int r = query[1];
            int cnt = 0;

            for(int i=l; i<=r; i++){    // O(R-L+!)
                if(prime[i]){
                    cnt++;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
// Time Complexity : O(N*loglogN) + O(Q)*O(N)  --> O(N*loglogN) + O(Q*N)
// Auxiliary Space : O(N)
// Output Space : O(Q)


// Using Sieve + PrefixSum
class SolutionOptimal {
private:
    vector<int> getPrimesTillMax(){
        long long n = INT32_MAX;

        vector<int> prime(n+1, 1);

        prime[0]=prime[1] = 0;

        for(int i=2; i<=n/i; i++){
            if(prime[i]){
                for(long long j=i*i; j<=n; j+=i){
                    prime[j] = 0;
                }
            }
        }

        return prime;
    }

public:
    vector<int> countPrimeInRange(vector<vector<int>> queries){
        vector<int> prefixPrimeCnt = getPrimesTillMax();    // O(N)

        for(long i=1; i<prefixPrimeCnt.size(); i++){    // O(N)
            prefixPrimeCnt[i]+=prefixPrimeCnt[i-1];
        }

        vector<int> ans;

        for(auto query : queries){  // O(Q)
            int L = query[0];
            int R = query[1];

            int cnt = prefixPrimeCnt[R] - (L>1?prefixPrimeCnt[L-1]:0);
            ans.push_back(cnt);
        }

        return ans;
    }
};
// Time Complexity : O(N*loglogN) + O(N) + O(Q)
// Space Complexity : O(N)


class SolutionOptimalMaxR {
public:
    vector<int> countPrimeInRange(vector<vector<int>> queries){
        if(queries.empty()) return {};

        int maxR = 0;
        for(const auto& query : queries){   // O(Q)
            maxR = max(maxR, query[1]);
        }

        vector<int> primeCnt(maxR+1, 1);    // O(N)

        // Get the Prime till MaxR
        primeCnt[0] = 0;
        if(maxR>0) primeCnt[1] = 0;

        for(int i=2; i<=maxR/i; i++){   // O(N*loglog(N))
            if(primeCnt[i]){
                for(long long j=1LL*i*i; j<=maxR; j+=i){
                    primeCnt[j] = 0;
                }
            }
        }

        // Prefix Sum of Prime
        for(int i=1; i<=maxR; i++){     // O(N)
            primeCnt[i]+=primeCnt[i-1];
        }

        vector<int> ans;

        for(const auto& query : queries){   // O(Q)
            int L = query[0];
            int R = query[1];

            int cnt = primeCnt[R] - (L>0?primeCnt[L-1]:0);
            ans.push_back(cnt);
        }

        return ans;
    }
};
// Time Complexity : O(2*Q) + O(2*N) + O(N* loglogN)
// Space Complexity : O(N)