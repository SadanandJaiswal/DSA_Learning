#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void subSeq(int i, int n, vector<int> vec, int *arr) {
    if (i >= n) {
        for (int j = 0; j < vec.size(); j++) {
            cout << vec[j] << " ";
        }
        if(vec.size()==0){
            cout<<"{}"<<endl;
        }
        cout << endl; 
        return;
    }

    // vec.push_back(arr[i]);
    // subSeq(i + 1, n, vec, arr);
    // vec.pop_back();
    // subSeq(i + 1, n, vec, arr);

    // reverse order
    subSeq(i + 1, n, vec, arr);
    vec.push_back(arr[i]);
    subSeq(i + 1, n, vec, arr);
    vec.pop_back();
}

int main() {
    int arr[6] = {3, 2, 1, 6, 8, 9};
    vector<int> vec;

    // Measure time taken
    auto start = high_resolution_clock::now();

    subSeq(0, 3, vec, arr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}


// time complexity: O(2^n)*n; *n is for printing the loop
// space complexity: O(n);  --> because maximum deept of recursion we are having is of n 
