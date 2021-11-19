class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        set<int> odd,even;
        int level=0;
        queue<int> q;        
        vector<int> vis(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(vis[i]){
                continue;
            }
            q.push(i);
            while(!q.empty()){
                int size=q.size();
                while(size--){
                    int node=q.front();q.pop();
                    vis[node]=1;
                    if(level&1){
                        odd.insert(node);
                    }else{
                        even.insert(node);
                    }
                    // if(graph[node].size()==0){
                    //     return false;
                    // }
                    for(auto it:graph[node]){
                        if(!vis[it]){
                            q.push(it);                        
                        }else{
                            if(((level&1) &&odd.count(it))||((level%2==0) &&even.count(it))){
                                return false;
                            }
                        }

                    }
                }
                level++;
            }
        }
        return true;
    }
};