#include <bits/stdc++.h>
using namespace std;

int fnSum(int n) {
    if (n == 0)
        return 0;

    return fnSum(n - 1) + n;
}

int fnFactorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    
    return n*fnFactorial(n-1);
}

int fnFibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fnFibo(n-1) + fnFibo(n-2);
}

// example of backtracking
void fn12n(int n)
{
    if(n==0) return;    // count == n return ;
    fn12n(n-1);         // fn12n(count+1)
    cout<<n<<" ";
}

// example of recursion
void fnn21(int n)
{
    if(n==0) return;
    cout<<n<<" ";
    fnn21(n-1);
}

int main() {
    int n;
    
    // Taking input for the value of n
    cout << "Enter a positive integer: ";
    cin >> n;

    // // Calling the function and displaying the result
    cout << "Sum of the first " << n << " natural numbers: " << fnSum(n) << endl;
    
     cout << "factorial of the  " << n << " " << fnFactorial(n) << endl;
     
     cout << "fibonacci of the  " << n << " " << fnFibo(n) << endl;
     
     cout<<"natural number till "<<n<<endl;
     
     fn12n(n);
     
     cout<<endl<<"natural number in reverse from "<<n<<endl;
     
     fnn21(n);
     

    return 0;
}
