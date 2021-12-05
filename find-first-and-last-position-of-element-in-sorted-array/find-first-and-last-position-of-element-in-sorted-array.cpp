class Solution {
public:
    int firstposition(vector<int>& arr,int target){
        int left=0,right=arr.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mid>0 && arr[mid]==target && arr[mid-1]!=target){
                return mid;
            }else if(mid==0&&arr[mid]==target){
                return mid;
            }else if(arr[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;
    }
    int lastposition(vector<int>& arr,int target){
        int left=0,right=arr.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mid<arr.size()-1 && arr[mid]==target && arr[mid+1]!=target){
                return mid;
            }else if(mid==arr.size()-1&&arr[mid]==target){
                return mid;
            }else if(arr[mid]<=target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return vector<int>({-1,-1});
        }
        int first = firstposition(nums,target);
        int last = lastposition(nums,target);
        return vector<int>({first,last});
    }
};