class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||!grid[i][j]){
            return 0;
        }
        grid[i][j]=0;
        int sum=1;
        sum+=dfs(grid,i+1,j);
        sum+=dfs(grid,i,j+1);
        sum+=dfs(grid,i-1,j);
        sum+=dfs(grid,i,j-1);
        return sum;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid,int mx=INT_MIN) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    mx=max(mx,dfs(grid,i,j));
                }
            }
        }
        return mx==INT_MIN?0:mx;
    }
};