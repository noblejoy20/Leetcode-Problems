typedef pair<int,pair<int,int>> pp;
class Solution {
private:
    
    int x[4]={1,0,-1,0};
    int y[4]={0,1,0,-1};
public:
    bool bfs(vector<vector<int>>& grid,int threshold){
        int m = grid.size();
        int n = grid[0].size();
        int mn=0;
        priority_queue<pp,vector<pp>,greater<pp>> q;
        
        vector<vector<int>> vis(m,vector<int>(n,false));
        q.push({0,{0,0}});
        vis[0][0]=true;
        
        while(!q.empty()){
            auto it=q.top();q.pop();
            int row = it.second.first;
            int col = it.second.second;
            if(row == m-1 && col == n-1) return true;
            int curr=grid[row][col];
            for(int i=0;i<4;i++){
                if(row+x[i]>=0 && row+x[i]<m && col+y[i]>=0 && col+y[i]<n && !vis[row+x[i]][col+y[i]]){       
                    int next = grid[row+x[i]][col+y[i]];
                    if(abs(next-curr)<=threshold){
                        vis[row+x[i]][col+y[i]]=true;
                        q.push({abs(next-curr),{row+x[i],col+y[i]}});
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int low=0,high = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                high = max(high,grid[i][j]);
            }
        }
        int ans=0;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(bfs(grid,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};