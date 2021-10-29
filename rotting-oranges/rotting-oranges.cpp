```c++
class Solution {
public:
    int dirx[4]={0,1,-1,0};
    int diry[4]={1,0,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,level=0;
        queue<pair<int,int>> q; // initialize the queue for BFS.
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    //count the fresh oranges with count variable.
                    count++;
                }
                if(grid[i][j]==2){
                    // push the rotten oranges in the queue
                    q.push({i,j});
                }
            }
        }
        //If no fresh oranges return zero.
        if(count==0){
            return 0;
        }
        //Do BFS.
        while(!q.empty()){
            int size=q.size();
            while(count>0 && size--){
                auto rotten=q.front();q.pop();
                for(int i=0;i<4;i++){
                    //Do boundary check and insert the four directional fresh oranges which will get rottened in next minute.
                    if(rotten.first+dirx[i]>=0 && rotten.first+dirx[i]<grid.size() && rotten.second+diry[i]>=0 && rotten.second+diry[i]<grid[0].size() && grid[rotten.first+dirx[i]][rotten.second+diry[i]]==1){
                        //make the fresh orange rottened.
                        grid[rotten.first+dirx[i]][rotten.second+diry[i]]=2;
                        q.push({rotten.first+dirx[i],rotten.second+diry[i]});
                        //decreament the fresh oranges which are rottened.
                        count--;
                    }
                }                
            }
            //minimum time counter.
            level++;
            //if count is zero return minimum time.
            if(count==0){
                return level;
            }
        }
        //if nothing found return -1.
        return -1;
    }
};
```
