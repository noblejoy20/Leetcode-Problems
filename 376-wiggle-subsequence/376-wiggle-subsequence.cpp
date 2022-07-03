class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        bool flag;
        int i=0;
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        if(i+1==nums.size()){
            return 1;
        }
        if(nums[i+1]-nums[i]>0){
            flag=true;
        }else{
            flag=false;
        }
        int count=1;
        for(int k=i+2;k<nums.size();k++){
            if(nums[k]-nums[k-1]>0){
                if(!flag){
                    count++;
                    flag=!flag;
                }
            }else if(nums[k]-nums[k-1]<0){
                if(flag){
                    count++;
                    flag=!flag;
                }
            }
        }
        return count+1;
    }
};