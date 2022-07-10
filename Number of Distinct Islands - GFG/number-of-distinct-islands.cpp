// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
 string dfs(int i,int j,vector<vector<int>>& grid,string count){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0){
            return "";
        }
        grid[i][j]=0;
        string right = "r" + dfs(i,j+1,grid,count);
        string top = "t" + dfs(i-1,j,grid,count);
        string bottom = "b" + dfs(i+1,j,grid,count);
        string left = "l" + dfs(i,j-1,grid,count);
        return right+top+bottom+left;
    }
class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<string> s;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                string count="";
                if(grid[i][j]){
                    s.insert(dfs(i,j,grid,count));
                }
            }
        }
        return s.size();
    }
};


// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}  // } Driver Code Ends