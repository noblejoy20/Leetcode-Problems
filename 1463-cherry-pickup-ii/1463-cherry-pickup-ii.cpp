class Solution {
public:
    int dp[80][80][80];
    int dfs(int r,int c1,int c2,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(r==n) return INT_MIN;
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int col1=c1+i;
                int col2=c2+j;
                if(col1>=0 && col1<m && col2>=0 && col2<m){
                    ans=max(ans,dfs(r+1,col1,col2,grid));
                }
            }
        }
        if(c1==c2) ans+=grid[r][c1];
        else ans+=(grid[r][c1]+grid[r][c2]);
        return dp[r][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return dfs(0,0,m-1,grid);
    }
};