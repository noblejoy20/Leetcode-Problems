class Solution {
public:
    //Book Allocation Problem
    bool isPossible(vector<int>& arr,int val,int st){
        int ans=0,i=0;
        while(st>0&&i<arr.size()){
           if(ans + arr[i]<=val){
               ans+=arr[i];               
           }else{
               ans = arr[i];
               st--;
           }
           i++;
        } 
        if(st==0) return false;
        return true;
    }
    
    int splitArray(vector<int>& arr, int m) {
        int n = arr.size();
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(isPossible(arr,mid,m)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};