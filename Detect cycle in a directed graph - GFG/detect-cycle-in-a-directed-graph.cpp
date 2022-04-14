// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool dfs(int V,vector<int> adj[],vector<bool>& vis,int i,vector<bool>& dfscall){
        
        for(auto it:adj[i]){
            if(vis[it] && dfscall[it]) return true;
            //if(vis[it]) return false;
            if(!vis[it])
            {
                vis[it]=true;
                dfscall[it]=true;
                if(dfs(V,adj,vis,it,dfscall)) return true;
                dfscall[it]=false;
            }
        }
        
        return false;   
        
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> dfscall(V,false);
        for(int i=0;i<V;i++){
            vis[i]=true;
        dfscall[i]=true;
            if(dfs(V,adj,vis,i,dfscall)) return true;
            dfscall[i]=false;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends