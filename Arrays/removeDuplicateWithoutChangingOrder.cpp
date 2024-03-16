// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicate(int * arr, int n)
{
    vector<int> result;
    set<int> seen;
    for(int i=0; i<n; i++)
    {
        if(seen.find(arr[i]) == seen.end()){
            result.push_back(arr[i]);
            seen.insert(arr[i]);
        }
    }
    return result;
}

void printVector(vector<int> v)
{
    for(int num: v)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}


int main() {
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin >>n;
        int arr[n] ;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        
        vector<int> v = removeDuplicate(arr,n);
        
        printVector(v);
    }
    
    
    

    return 0;
}