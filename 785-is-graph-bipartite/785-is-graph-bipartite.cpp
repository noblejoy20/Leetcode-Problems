class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        set<int> odd,even;
        queue<int> q;
        int level=0;
        vector<bool> vis(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            if(vis[i]) continue;            
            q.push(i);            
            while(!q.empty()){
                int size = q.size();
                for(int i=0;i<size;i++){
                    int val = q.front();q.pop();
                    vis[val]=true;
                    if(level&1){
                        if(even.count(val)) return false;
                        odd.insert(val);
                    }else{
                        if(odd.count(val)) return false;
                        even.insert(val);
                    }
                    for(auto it:graph[val]){
                        if(!vis[it]){
                            q.push(it);
                        }
                    }
                }
                level++;            
            }
        }
        return true;
    }
};