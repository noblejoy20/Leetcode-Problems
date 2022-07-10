class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        int tot=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    tot++;
                }
                if(grid[i][j]==1){
                    tot++;
                }
            }
        }
        if(tot==0) return 0;
        int x[5]={0,-1,0,1,0};
        int count=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();q.pop();
                tot--;
                int row = it.first,col=it.second;
                for(int k=0;k<4;k++){
                    if(row+x[k]<0||col+x[k+1]<0||row+x[k]>=m||col+x[k+1]>=n||grid[row+x[k]][col+x[k+1]]==0||grid[row+x[k]][col+x[k+1]]==2){
                        continue;
                    }
                    grid[row+x[k]][col+x[k+1]]=2;
                    q.push({row+x[k],col+x[k+1]});
                }
            }
            count++;  
        }
        return tot==0?count-1:-1;
    }
};