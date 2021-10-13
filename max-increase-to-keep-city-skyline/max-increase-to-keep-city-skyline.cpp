class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid,int sum=0) {
        // Maintain two arrays to store rowwise maximum and columnwise maximum
        int rowMax[grid.size()];
        int colMax[grid[0].size()];
        
        // initialise to min value -1
        memset(rowMax,-1,sizeof(rowMax));
        memset(colMax,-1,sizeof(colMax));
        
        // Store the corresponding values while traversing.
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                rowMax[i]=max(rowMax[i],grid[i][j]);
                colMax[j]=max(colMax[j],grid[i][j]);
            }
        }
        
        // Add up the buildings that require height increment.
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int temp = min(rowMax[i],colMax[j])-grid[i][j];
                sum+=temp>0?temp:0;
            }
        }
        return sum;
    }
};