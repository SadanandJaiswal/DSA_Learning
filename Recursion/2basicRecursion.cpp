// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// functional recursion
int fn(int n){
    if(n==0) return 1;
    return n * fn(n-1); // waiting for something
}

// parameterised recursion
void fnsum(int i, int sum){ // using parameter sum
    if(i==0) {
        cout<<sum;
        return ;
    }
    fnsum(i-1,sum+i);
}

// reverse array using recursion
void fnReverse(int * arr, int s, int e){
    if(s>=e) return ;
    swap(arr[s],arr[e]);
    fnReverse(arr,s+1, e-1);
}
// insted of e we can take e as n-s-1, and condition to be i>=n/2;

// print array
void fnPrint(int * arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// functional recursion of checking string is palindrome or not
bool palindrome(string str, int s, int e)
{
    if(s>=e){
        return true;
    }
    if (str[s] != str[e])
    {
        return false;
    }
    return palindrome(str,s+1,e-1);
}


int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    
    int n;
    cin>>n;
    cout<<endl;
    
    // sum of n natural number
    int sum =0;
    fnsum(n,sum);
    cout<<fn(n);


    // reverse array using recursion
    int arr[5] = {1,2,3,4,5};
    int arr2[4] = {4,3,2,1};
    
    cout<<endl;
    fnReverse(arr,0,4);
    fnPrint(arr,5);
    
    fnReverse(arr2,0,3);
    fnPrint(arr2,4);


    // palindrome
    string s1 = "abcdcba";
    string s2 = "abcd";
    
    cout<<palindrome(s1,0,s1.size()-1)<<endl;
    cout<<palindrome(s2,0,s2.size()-1)<<endl;

    return 0;
}