class Solution {
public:
    int sumGreater(int idx,int target,vector<int>& nums){
        int left=0;
        int right=idx;
        int count=0;
        while(left<right){
            if(nums[left]+nums[right]<=target){
                left++;
            }else{
                count+=right-left;
                right--;
            }
        }
        return count;
    }
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int c=nums.size()-1;c>=0;c--){
            ans+=sumGreater(c-1,nums[c],nums);
        }
        return ans;
    }
};