#include <bits/stdc++.h>
using namespace std;
class SolutionBruteForce {
  public:
    int recursivePower(int n, int p) {
        // code here
        int ans = 1;

        for(int i=1; i<=p; i++){
            ans*=n;
        }

        return ans;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)



class SolutionOptimalRecursive {
  public:
    int powerOfn(int n, int p){
        // Base Condition : Number to the power zero is 1
        if(p==0){
            return 1;
        }
        
        int half = powerOfn(n*n, p/2);
        
        if(p&1){
            return half*n;
        }
        
        return half;
    }
    
    int recursivePower(int n, int p) {
        // code here
        return powerOfn(n, p);
    }
};
// Time Complexity : O(logn)
// Space Complexity : O(1)


class SolutionOptimalIterative {
  public:
    double recursivePower(int n, int p) {
        // code here
        double ans = 1;
        long long power = p;
        double base  = n;

        if(p<0){
            power = -p;
        }
        
        while(power>0){
            if(power&1){
                ans*=base;
            }
            
            base*=base;
            power/=2;
        }

        if(p<0) return 1.0/ans;
        
        return ans;
    }
};
// Time Complexity : O(logn)
// Space Complexity : O(1)




