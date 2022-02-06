class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low =-1,high=0,count=0;
        int temp=nums[0];
        while(high<nums.size()){
            if(nums[high]==temp){
                count++;
                if(count==1||count==2){
                    nums[++low]=nums[high];
                }                
            }else{
                temp=nums[high];
                count=1;
                if(count==1){
                    nums[++low]=nums[high];
                }                
            }
            high++;
        }
        return low+1;
    }
};