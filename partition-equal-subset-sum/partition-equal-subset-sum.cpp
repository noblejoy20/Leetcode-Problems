class Solution {
public:
    bool solve(vector<int>& nums,int target,int curr,int idx,vector<vector<int>>& dp){
        if(curr>target||idx==nums.size()){
            return false;
        }
        if(curr==target){
            return true;
        }
        if(dp[curr][idx]!=-1){
            return dp[curr][idx];
        }
        //yes
        //cout<<curr<<" "<<idx<<"\n";
        int ans = solve(nums,target,curr+nums[idx],idx+1,dp);
        dp[curr][idx]=ans?1:0;
        if(ans) return true;
        //no
        int res = solve(nums,target,curr,idx+1,dp);
        dp[curr][idx]=res?1:0;
        if(res) return true;
        
        return dp[curr][idx];
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(target+1,vector<int>(nums.size()+1,-1));
        return solve(nums,target,0,0,dp);
    }
};