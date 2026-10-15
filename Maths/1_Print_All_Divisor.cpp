#include<bits/stdc++.h>
using namespace std;

class SolutionBruteForce {
  public:
    vector<int> getDivisors(int n) {
        // code here
        vector<int> ans;
        
        for(int i=1; i<=n; i++){
            if(n%i==0) ans.push_back(i);
        }
        
        return ans;
    }
};
// Time Complexity: O(n), where n is the number of times we can check for divisibility.
// Space Complexity: O(1), as we are using a constant amount of space for the ans vector.


/*
    WE can see :
    n = 36 , Divisors = 1, 2, 3, 4, 6, 9, 12, 18, 36
    1*36, 2*18, 3*12, 4*9, 6*6
    So we can see that the divisors are in pairs, and the pairs are (1, 36), (2, 18), (3, 12), (4, 9), (6, 6)

    We need to travel till sqrt(n) to find the divisors, and for each divisor we can find its pair by dividing n by the divisor.
*/

class SolutionOptimalSorted {
  public:
    vector<int> getDivisors(int n) {
        // code here
        vector<int> ans1, ans2;
        
        for(int i=1; i*i<=n; i++){
            if(n%i==0){
                ans1.push_back(i);
                
                if(i!=n/i){
                    ans2.push_back(n/i);
                }
            }
        }
        
        for(int i=ans2.size()-1; i>=0; i--){
            ans1.push_back(ans2[i]);
        }
        
        return ans1;
    }
};
// Time Complexity: O(sqrt(n)), where n is the number of times we can check for divisibility.
// Space Complexity: O(1), as we are using a constant amount of space for the