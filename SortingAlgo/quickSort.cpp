#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v) {
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v = {4,2,7,3,9};
    printVec(v);   
}