class Solution {
public:
     void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int left=0,right=grid[0].size()-1,top=0,bottom=grid.size()-1;
        for(int i=left;i<=right;i++){
            if(grid[top][i]){
                dfs(grid,top,i);
            }
        }
        for(int i=top;i<=bottom;i++){
            if(grid[i][right]){
                dfs(grid,i,right);
            }
        }
        for(int i=right;i>=left;i--){
            if(grid[bottom][i]){
                dfs(grid,bottom,i);
            }
        }
        for(int i=bottom;i>=top;i--){
            if(grid[i][left]){
                dfs(grid,i,left);
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};