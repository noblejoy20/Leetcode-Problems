class Solution {
public:
    unordered_map<int,vector<int>> edges;
    vector<vector<int>> result;
    int time=0;
    
    void dfs(int curr,int parent,vector<int>& lowTime,vector<int>& visitedTime,vector<bool>& visited){
        //make node visited
        visited[curr]=true;
        //initialise the time for the low and visited
        lowTime[curr]=visitedTime[curr]=time++;
        
        for(int neighbour:edges[curr]){
            if(neighbour==parent) continue; // neighbour is equal to parent then return.
            
            // if not visited perform bfs on neighbour as current node and current node as parent.
            if(!visited[neighbour]){
                dfs(neighbour,curr,lowTime,visitedTime,visited);
                
                //back propogate the low time value.
                lowTime[curr]=min(lowTime[curr],lowTime[neighbour]);
                
                //if current node's visited time is less than the low time of neighbour then we have found critical edge.
                if(visitedTime[curr]<lowTime[neighbour]){
                    result.push_back(vector<int>({neighbour,curr}));
                }
            }else{
                //if node is visited and is not parent then it means it is a back edge 
                //Update the minimum of current lowtime node and back edge visitedtime node.
                lowTime[curr]=min(lowTime[curr],visitedTime[neighbour]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //lowTime,visitedTime and visited array
        vector<int> lowTime(n,0),visitedTime(n,0);
        vector<bool> visited(n,false);
        
        //adjacency list
        for(auto conn:connections){
            edges[conn[0]].push_back(conn[1]);
            edges[conn[1]].push_back(conn[0]);
        }
        
        //dfs
        dfs(0,-1,lowTime,visitedTime,visited);
        
        return result;
    }
};