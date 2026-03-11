
class Solution {
  public:
    void merge(int start, int mid, int end, vector<int> &count, vector<pair<int,int>> &v){
        int i=start, j=mid+1, k=0;
        
        vector<pair<int,int>> temp(end-start+1);
        
        while(i<=mid && j<=end){
            if(v[i].first<v[j].first){
                count[v[i].second]+= end-j+1;
                temp[k++] = v[i++];
            }else{
                temp[k++] = v[j++];
            }
        }
        
        while(i<=mid){
            temp[k++] = v[i++];
        }
        
        while(j<=end){
            temp[k++] = v[j++];
        }
        
        for(int i=0; i<temp.size(); i++){
            v[start+i] = temp[i];
        }
    }
    
    void mergeSort(int start, int end, vector<int> &count, vector<pair<int,int>> &v){
        if(start>=end){
            return;
        }
        
        int mid = start + (end-start)/2;
        
        mergeSort(start, mid, count, v);
        mergeSort(mid+1, end, count, v);
        merge(start, mid, end, count, v);
    }
    
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n= arr.size();
        vector<int> count(n,0);
        vector<pair<int,int>> v(n);
        
        for(int i=0; i<n; i++){
            v[i] = {arr[i], i};
        }
        
        mergeSort(0, n-1, count, v);
        
        vector<int> ans;
        
        for(int ind : indices){
            ans.push_back(count[ind]);
        }
        
        return ans;
    }
};