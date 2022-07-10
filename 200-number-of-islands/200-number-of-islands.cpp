class Solution {
public:
    int dir[5]={0,-1,0,1,0};
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    queue<pair<int,int>> q;
                    grid[i][j]='0';
                    q.push({i,j});
                    while(!q.empty()){
                        auto val = q.front();q.pop();
                        
                        for(int i=0;i<=3;i++){
                            if(val.first+dir[i]<0||val.second+dir[i+1]<0||val.first+dir[i]>=m||val.second+dir[i+1]>=n||grid[val.first+dir[i]][val.second+dir[i+1]]=='0'){
                                continue;
                            }
                            grid[val.first+dir[i]][val.second+dir[i+1]]='0';
                            q.push({val.first+dir[i],val.second+dir[i+1]});
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};