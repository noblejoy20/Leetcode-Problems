class Solution {
public:
    int dirx[4]={0,1,-1,0};
    int diry[4]={1,0,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,level=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(count==0){
            return 0;
        }
        while(!q.empty()){
            int size=q.size();
            while(count>0 && size--){
                auto rotten=q.front();q.pop();
                for(int i=0;i<4;i++){
                    if(rotten.first+dirx[i]>=0&&rotten.first+dirx[i]<grid.size()&&rotten.second+diry[i]>=0&&rotten.second+diry[i]<grid[0].size()&&grid[rotten.first+dirx[i]][rotten.second+diry[i]]==1){
                        grid[rotten.first+dirx[i]][rotten.second+diry[i]]=2;
                        q.push({rotten.first+dirx[i],rotten.second+diry[i]});
                        count--;
                    }
                }                
            }
            level++;
            if(count==0){
                return level;
            }
        }
        return -1;
    }
};