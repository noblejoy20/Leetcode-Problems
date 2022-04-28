typedef pair<int,pair<int,int>> pp;
class Solution {
private:
    priority_queue<pp,vector<pp>,greater<pp>> q;
    int x[4]={1,0,-1,0};
    int y[4]={0,1,0,-1};
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        q.push({0,{0,0}});
        
        while(!q.empty()){
            auto it=q.top();q.pop();
            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(val>dist[row][col]) continue;
            if(row == m-1 && col == n-1) return val;
            int curr=grid[row][col];
            for(int i=0;i<4;i++){
                if(row+x[i]>=0 && row+x[i]<m && col+y[i]>=0 && col+y[i]<n){
                    int next = grid[row+x[i]][col+y[i]];
                    int mn =max(val,abs(next-curr));
                    if(dist[row+x[i]][col+y[i]]>mn){
                        dist[row+x[i]][col+y[i]]=mn;
                        q.push({dist[row+x[i]][col+y[i]],{row+x[i],col+y[i]}});
                    }
                }
            }
        }
        return -1;
    }
};