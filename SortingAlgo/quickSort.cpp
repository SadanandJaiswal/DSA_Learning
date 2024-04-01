// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int low, int high){
    int pivot = v[low];
    int i = low;
    int j = high;
    while(i<j){
        while(v[i]<=pivot && i<=high)
        {
            i++;
        }
        while(v[j]>pivot && j>=low)
        {
            j--;
        }
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    
    swap(v[j], v[low]);
    return j;
}

void quickSort(vector<int> &v, int low, int high)
{
    if(low<high){
        int partitionIndex = partition(v,low,high);
        quickSort(v, low, partitionIndex-1);
        quickSort(v, partitionIndex+1, high);
    }
}

int main() {
    vector<int> v= {4,6,2,5,9,1,3};
    quickSort(v, 0 , v.size()-1);
    
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}