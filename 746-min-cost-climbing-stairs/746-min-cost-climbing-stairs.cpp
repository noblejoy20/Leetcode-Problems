class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()+1];
        memset(dp,0,sizeof(dp));
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=cost.size();i++){
            dp[i]=(i<cost.size()?cost[i]:dp[i])+min(dp[i-1],dp[i-2]);
        }
        return dp[cost.size()];
    }
};