class Solution {
public:
    int calcFloor(vector<int>& arr,int x){
        int left=0,right=arr.size()-1,ans=-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(arr[mid]<=x){
                ans = mid;
                left = mid+1;
            }else {
                right = mid-1;
            }
        }
        return ans;
    }
    int calcCeil(vector<int>& arr,int x){
        int left=0,right=arr.size()-1,ans=arr.size();
        while(left<=right){
            int mid = left + (right - left)/2;
            if(arr[mid]<=x){                
                left = mid+1;
            }else {
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int floor = calcFloor(arr,x);
        int ceil = calcCeil(arr,x);
        vector<int> ans;
        while(k>0 && floor>=0 && ceil<arr.size()){
            if(abs(x-arr[floor])<=abs(x-arr[ceil])){
                ans.push_back(arr[floor]);
                floor--;
            }else{
                ans.push_back(arr[ceil]);
                ceil++;
            }
            k--;
        }
        while(k>0 && floor>=0){
            ans.push_back(arr[floor]);
            floor--;
            k--;
        }
        while(k>0 && ceil<arr.size()){
            ans.push_back(arr[ceil]);
            ceil++;
            k--;
        }
        sort(ans.begin(),ans.end());
         return ans;
    }
};