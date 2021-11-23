class Solution {
public:
    vector<vector<int>> ans;
    void permuteHelper(vector<int>& nums,vector<int>& result,int start){
        if(start==nums.size()){
           ans.push_back(result);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(result[i]==INT_MIN){
                result[i]=nums[start];
                permuteHelper(nums,result,start+1);
                result[i]=INT_MIN;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> result(nums.size(),INT_MIN);
        int i=0;
        permuteHelper(nums,result,i);
        return ans;
    }
};