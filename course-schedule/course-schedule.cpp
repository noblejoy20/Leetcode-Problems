class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& graph,int src,vector<bool>& vis,vector<bool>& done){
        if(graph.find(src)==graph.end()){
            return true;
        }
        if(done[src]){
            return true;
        }
        vis[src]=done[src]=true;        
        for(auto it:graph[src]){
            if(!vis[it]){
                if(!dfs(graph,it,vis,done)) return false;         
            }else{
                return false;
            }
        }
        vis[src]=false;     
        return true;
    }
    bool canFinish(int num, vector<vector<int>>& req) {
        unordered_map<int,vector<int>> graph;
        for(auto it:req){
            graph[it[0]].push_back(it[1]);
        }
         vector<bool> vis(num,false);
        vector<bool> done(num,false);
        for(auto it=graph.begin();it!=graph.end();it++){
            if(!done[it->first] && !dfs(graph,it->first,vis,done)){                
                return false;
            }
        }
        return true;
    }
};