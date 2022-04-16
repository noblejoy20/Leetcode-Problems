class Solution {
public:
    bool solve(vector<vector<int>>& graph,vector<bool>& vis,vector<bool>& dfs,int src){
        for(auto nbr:graph[src]){
            if(!vis[nbr]){
                vis[nbr]=true;
                dfs[nbr]=true;
                if(solve(graph,vis,dfs,nbr)) return true;
                dfs[nbr]=false;
            }else if(dfs[nbr]){
                return true;
            }
        }
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false);
        vector<bool> dfs(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                vis[i]=true;
                dfs[i]=true;
                if(solve(graph,vis,dfs,i)) continue;
                dfs[i]=false;
            }
        }
        for(int i=0;i<dfs.size();i++){
            if(!dfs[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};