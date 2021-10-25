class Solution {
public:
    //adjacency list creation;
    unordered_map<int,vector<int>> mp;
    //maintain the current time to reach the node.
    int time=0;
    void dfs(int u,vector<int>& low,vector<int>& disc,vector<int>& parent,vector<vector<int>>& result){
        low[u]=disc[u]=time++;
        for(auto i:mp[u]){
            if(disc[i]==-1){
                parent[i]=u;//set the parent node
                dfs(i,low,disc,parent,result);// do dfs
                low[u]=min(low[u],low[i]);//minimum time to reach closest node
                if(low[i]>disc[u]){// if any of the neighbours have discovery time less than current low time (bridge)
                    result.push_back(vector<int>({u,i}));
                }
            }else if(i!=parent[u]){//if current node is not the parent of incoming node
                low[u]=min(low[u],disc[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //Tarjan's algorithm for low time and discovery time and to maintain the parent node;
        vector<int> low(n,-1),disc(n,-1),parent(n,-1);
        //adjacency list creation;
        for(auto conn:connections){
            mp[conn[0]].push_back(conn[1]);
            mp[conn[1]].push_back(conn[0]);
        }
        vector<vector<int>> result;
        //Depth-first search
        dfs(0,low,disc,parent,result);
        return result;
    }
};