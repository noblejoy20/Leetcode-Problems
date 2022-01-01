class Solution {
public:
    unordered_map<string,int> mp;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        
        memset(dp,0,sizeof(dp));
        
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