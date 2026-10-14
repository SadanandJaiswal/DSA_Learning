#include<bits/stdc++.h>
using namespace std;

class SolutionBruteForce  {
    int XORinRange(int l, int r){
        int ans = 0;
        for(int i=l;i<=r;i++){
            ans^=i;
        }
        return ans;
    }
};
// Time Complexity: O(n), where n is the number of elements in the input vector nums.
// Space Complexity: O(1), as we are using a constant amount of space for the XOR calculation.


/*
    We can Obsserve a pattern

    XOR till 1 = 1
    XOR till 2 = 3
    XOR till 3 = 0
    XOR till 4 = 4

    XOR till 5 = 1
    XOR till 6 = 7
    XOR till 7 = 0
    XOR till 8 = 8

    We can see that the patter repeats after every 4 numbers
    And Xor till n%4==1 is 1
    Xor till n%4==2 is n+1
    Xor till n%4==3 is 0
    Xor till n%4==0 is n
*/
class SolutionOptimal {
  private:
    int XorTillN(int n){
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
        else return n;
    }
    
  public:
    int findXOR(int l, int r) {
        // We have function to find the xor from 1 to N
        // But we need to find from L to R
        
        // XOR in range 1 to L-1 : L=4 -> xor1 = 1^2^3
        // XOR in range 1 to R : L=7 -> xor2 = 1^2^3^4^5^6^7
        
        // We we XOR both the xor then xor till L-1 will gets cancelled, because xor of sam enumber is 0 and xor of number with 0 is the number itself
        
        return XorTillN(l-1)^XorTillN(r);
    }
};
// Time Complexity: O(1), as we are using a constant amount of time for the XOR calculation.
// Space Complexity: O(1), as we are using a constant amount of space for the XOR calculation.