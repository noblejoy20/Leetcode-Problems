class Solution {
    public int getLow(int[] nums,int target){
        int low=0,high=nums.length-1;//set high and low values
        int ans=-1;//potential low value if not found in array;
        
        //binary search
        while(low<=high){
            int mid=low+(high - low)/2;
            
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }  
        }
        return ans;
    }
    public int getHigh(int[] nums,int target){
        int low=0,high=nums.length-1;//set high and low values
        int ans=-1;//potential high value if not found in array;
        
        while(low<=high){
            int mid=low+(high - low)/2;
            
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
            return ans;
    }
    public int[] searchRange(int[] nums, int target) {
        return new int[]{getLow(nums,target),getHigh(nums,target)};
    }
}