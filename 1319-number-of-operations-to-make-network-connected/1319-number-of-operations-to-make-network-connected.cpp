class Solution {
public:
    void dfs(vector<int>& vis,int src,vector<int> adj[]){
        vis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(vis,it,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(vis,i,adj);
                count++;
            }
        }
        return n-1<=connections.size()?count-1:-1;
    }
};

// 0 ---> 1,2,3
// 1 ---> 0,2,3
// 2 ---> 0,1
// 3 ---> 0,1

