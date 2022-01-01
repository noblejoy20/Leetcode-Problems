class Solution {
public:
    //https://www.youtube.com/watch?v=YzvF8CqPafI&ab_channel=Pepcoding
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        
        memset(dp,0,sizeof(dp));
        
        // Think of last balloon to burst and take all the options out.
        //General formula: dp[i,k-1]+dp[k+1,j]+nums[i-1]*nums[k]*nums[j+1];
        
        for(int g=0;g<n;g++){
           for(int i=0,j=g;j<n;i++,j++){
               int mx=INT_MIN;
               for(int k=i;k<=j;k++){
                   
                   int left=k==i?0:dp[i][k-1];
                   int right=k==j?0:dp[k+1][j];
                   int curr=(i==0?1:nums[i-1])*nums[k]*(j==n-1?1:nums[j+1]);
                   mx=max(mx,left+right+curr);
               }
               dp[i][j]=mx;
           }
        }
        return dp[0][n-1];
    }
};

