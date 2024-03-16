#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n<2) return n;
    return fibo(n-1) + fibo(n-2);
}

int main(){
    // int t;
    // cout<<"Enter the value of t : ";
    // cin>>t;
    
    // while(t--)
    // {
    //     int n;
    //     cout<<"Enter the value of n ("<<t<<"): ";
    //     cin>>n;

    //     cout<<"fibonacci of "<<n<<" is "<<fibo(n)<<endl;
    // }

    int fi=0, se=1;
    int n;
        // cout<<"Enter the value of n ("<<t<<"): ";
        cin>>n;

    cout<<"0 1 ";
    for(int i=2; i<=n; i++)
    {
        // fi=se;
        // se=fi+se;
        // cout<<se<<" ";
        int th = fi + se;
        cout<<th<<" ";
        fi=se;
        se = th;
    }

    return 0;
}