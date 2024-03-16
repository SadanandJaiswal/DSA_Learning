// // print subSequecne with sum k
// #include<bits/stdc++.h>
// using namespace std;

// void printArray(vector<int> v)
// {
//     for(int i=0; i<v.size(); i++)
//     {
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
// }

// void subSeqKSum(int i, int n, vector<int> v, int *arr, int sum, int refSum)
// {
//     // if(i>=n || sum>refSum)  // if non negative numbers are there
//     if(i>=n)    // if negative numbers are also present
//     {
//         if(sum==refSum)
//         {
//             printArray(v);
//         }
//         return;
//     }
    
//     v.push_back(arr[i]);
//     sum+=arr[i];
//     subSeqKSum(i+1,n,v,arr,sum,refSum);
//     v.pop_back();
//     sum-=arr[i];
//     subSeqKSum(i+1,n,v,arr,sum,refSum);
// }

// int main(){
//     int arr[3] = {1,2,1};
//     vector<int> vec;
//     int k =3;
//     int sum =0;
    
//     subSeqKSum(0,3,vec,arr,sum,k);

// }

// // time complexity: O(2^n * n) // n is number of elm in array
// // space complexity: O(n) // n is maximum depth of recursion


// <---------------------------------- return any subsequence -------------------------------->


// if print any subsequence with sum is equal to k
// print subSequecne with sum k

// we can do this by using flag but it will still run the remaing recursion until it complete the 2^n recursion
// use function to overcome the above problem
#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

bool subSeqKSum(int i, int n, vector<int> v, int *arr, int sum, int refSum)
{
    // if(i>=n || sum>refSum)  // if non negative numbers are there
    if(i>=n)    // if negative numbers are also present
    {
        if(sum==refSum)
        {
            printArray(v);
            return true;
        }
        else return false;
    }
    
    v.push_back(arr[i]);
    sum+=arr[i];
    if(subSeqKSum(i+1,n,v,arr,sum,refSum)==true) return true;
    v.pop_back();
    sum-=arr[i];
    if(subSeqKSum(i+1,n,v,arr,sum,refSum)==true) return true;
    
    return false;
}

int main(){
    int arr[3] = {1,2,1};
    vector<int> vec;
    int k =2;
    int sum =0;
    subSeqKSum(0,3,vec,arr,sum,k);
}


// <---------------------------------- return number of subsequence -------------------------------->

// print subSequecne with sum k
#include<bits/stdc++.h>
using namespace std;

int subSeqKSum(int i, int n, int *arr, int sum, int refSum)
{
   
    if(sum>refSum) return 0; // if array contains only positive numbers
    if(i>=n)    
    {
        if(sum==refSum)
        {
            return 1;
        }
        return 0;
    }
    
    sum+=arr[i];
    int l = subSeqKSum(i+1,n,arr,sum,refSum);
    sum-=arr[i];
    int r = subSeqKSum(i+1,n,arr,sum,refSum);
    
    return l+r;
}

int main(){
    int arr[3] = {1,2,1};
    int k =3;
    int sum =0;
    
    cout<<subSeqKSum(0,3,arr,sum,k);
    
    

}