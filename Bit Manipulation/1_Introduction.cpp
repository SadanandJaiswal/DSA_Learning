#include<bits/stdc++.h>
using namespace std;


// 1. Convert Decimal to Binary
string convert2Binary(int n){
    if(n==0) return "0";

    string ans = "";
    while(n!=0){
        ans += to_string(n%2);
        n/=2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
// Time Complexity: O(log(n)), where n is the decimal number to be converted to binary.
// Space Complexity: O(log(n)), for storing the binary representation in the string.

// 1.2 STL to convert Decimal to Binary
string convert2BinarySTL(int n){
    string ans = bitset<32>(n).to_string();
    int ind = ans.find('1');
    if(ind!=string::npos){
        return ans.substr(ind);
    }
    return "0";
}
// Time Complexity: O(1), as the size of the bitset is fixed (32 bits).
// Space Complexity: O(1), as the size of the bitset is fixed (32




// 2. Convert Binary to Decimal
int convert2Decimal(string s){
    int ans = 0;
    int n = s.size();
    int p = 1;
    for(int i=0; i<n; i++){
        // if(s[i]=='1'){
        //     ans+= 1<<(n-i-1);
        // }

        if(s[i]=='1'){
            ans+= p;
        }
        p*=2;
    }
    return ans;
}

// 2.2 STL to convert Binary to Decimal
int convert2DecimalSTL(string s){
    return stoi(s, nullptr, 2);
}




// 3. 1's Complement
string onesComplement(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            s[i]='1';
        }else{
            s[i]='0';
        }
    }
    return s;
}

// 4. 2's Complement
string twosComplement(string s){
    // 1's Complement
    s = onesComplement(s);

    // Add 1 to the LSB
    int n = s.size();
    for(int i=n-1; i>=0; i--){
        if(s[i]=='0'){
            s[i]='1';
            break;
        }else{
            s[i]='0';
        }
    }

    return s;
}


// Storing -ve : store in 2's complement form, and for +ve store in normal binary form.
// Not Operator : 1) Flip bits 2) Check if the number is negative, if yes then convert to 2's complement form. 3) Add 1 to the LSB. 4) Convert to decimal form.
// AND Operator : if all 1 then 1 else 0
// OR Operator : if any 1 then 1 else 0
// XOR Operator : if 1 is odd then 1 else 0
// Left Shift Operator : multiply by 2
// Right Shift Operator : divide by 2 