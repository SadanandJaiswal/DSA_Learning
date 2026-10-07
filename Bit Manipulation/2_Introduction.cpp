#include<bits/stdc++.h>
using namespace std;

// 1. Swap 2 Numbers
void swapUsingXor(int &a, int &b){
    a = a^b;

    // a^b^b
    b = a^b;    // b = (a^b)^b = a^(b^b) = a^0 = a

    // a^b^a^b
    a = a^b;    // a = (a^b)^a = (a^a)^b = 0^b = b
}

void swapUsingAddSub(int &a, int &b){
    a = a+b;
    b = a-b;    // b = (a+b)-b = a
    a = a-b;    // a = (a+b)-a = b
}


// 2. Check if ith bith is set or not
bool isIthBitSet(int n, int i){
    return (n & (1<<i)) != 0;
}

// **Note** : Computer perform bitwise operation much much faster than arithmetic operation. So, it is always better to use bitwise operation instead of arithmetic operation if possible.


// 3. Set the ith bit of a number
int setIthBit(int n, int i){
    return (n | (1<<i));
}


// 4. Clear the ith bit of a number
int clearIthBit(int n, int i){
    return (n & (~(1<<i)));
}


// 5. Toggle the ith bit of a number
int toggleIthBit(int n, int i){
    return (n ^ (1<<i));
}


// 6. Remove the last set bit of a number (Remember it)
int removeLastSetBit(int n){
    return (n & (n-1));
}


// 7. Check if number is power of 2 or not
bool isPowerOf2(int n){
    return (n>0 && (n & (n-1)) == 0);
}


// 8. Count the number of set bits in a number
int countSetBits(int n){
    int count = 0;
    while(n>0){
        count += n&1;
        n = n>>1;
    }
    return count;
}

// Using Brian Kernighan’s Algorithm
int countSetBitsBK(int n){
    int count = 0;
    while(n>0){
        n = n & (n-1);  // remove the rightmost set bit
        count++;
    }
    return count;
}

// Using STL
int countSetBitsSTL(int n){
    return __builtin_popcount(n);
}

