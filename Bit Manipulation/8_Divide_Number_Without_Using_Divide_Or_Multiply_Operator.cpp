#include<bits/stdc++.h>
using namespace std;

class SolutionBruteForce {
public:
    int divide(int dividend, int divisor) {

        if(dividend==divisor) return 1;

        long sum = 0;
        long quotient = 0;
        long neu = abs((long)dividend);
        long den = abs((long)divisor);
        bool sign = true;;

        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
            sign = false;
        }

        while(sum+den <= neu){
            quotient++;
            sum+=den;
        }

        if(quotient == (1L<<31) && sign){
            return INT32_MAX;
        }

        if(quotient == (1L<<31) && !sign){
            return INT32_MIN;
        }

        return sign?(int)quotient:(int)-quotient;
    }
};
// Time Complexity: O(n), where n is the number of times we can subtract the divisor from the dividend.
// Space Complexity: O(1), as we are usign a constant amount of space for the sum and count variables.


class SolutionNearOptimal {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;

        long quotient = 0;
        bool sign = !((dividend<0) ^ (divisor<0));

        long n = labs(dividend);
        long d = labs(divisor);

        while(n>=d){
               int cnt = 0;
               while(n>=d*pow(2,cnt+1)){
                    cnt++;
               }

               quotient+= pow(2,cnt);
               n -= d * pow(2,cnt);
        }

        if(quotient == (long)pow(2,31) && sign){
            return INT_MAX;
        }

        if(quotient == (long)pow(2,31) && !sign){
            return INT_MIN;
        }

        return sign?quotient:-quotient;
    }
};

class SolutionOptimal {
public:
int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;

        long quotient = 0;
        bool sign = !((dividend<0) ^ (divisor<0));

        long n = labs(dividend);
        long d = labs(divisor);

        while(n>=d){
               int cnt = 0;
               while(n >= (d<<(cnt+1))) {
                    cnt++;
               }

               quotient+= 1L<<cnt;
               n -= d<<cnt;
        }

        if(quotient == (1L<<31) && sign){
            return INT_MAX;
        }

        if(quotient == (1L<<31) && !sign){
            return INT_MIN;
        }

        return sign?quotient:-quotient;
    }
};