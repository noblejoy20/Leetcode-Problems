class Solution {
public:
// DFS (TLE)
//     void dfs(int node,vector<int> result[],int& ans,vector<int>& vis,int count){
//         ans=max(ans,count);
//         vis[node]=1;
//         for(auto it:result[node]){
//             if(!vis[it]){
//                 vis[it]=1;
//                 dfs(it,result,ans,vis,count+1);
//                 vis[it]=0;
//             }
//         }
//         vis[node]=0;
//     }
    
//     void reArrangeElements(vector<pair<int,int>>& res, int mx,int idx){
//         pair<int,int> pq=res.back();
                
//         if(pq.first>=mx){
//             while(pq.first>mx){
//                 res.pop_back();   
//                 if(res.size()==0) break;
//                 pq=res.back();
//             }
//             res.push_back({mx,idx}); 
//         }   
//     }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<int> result[n];
//         vector<int> vis(n,0);
//         vector<pair<int,int>> res;
//         vector<int> output;
        
//         for(auto it:edges){
//             result[it[0]].push_back(it[1]);
//             result[it[1]].push_back(it[0]);
//         }
        
        
//         for(int i=0;i<n;i++){
//             int mx=INT_MIN;
            
//             dfs(i,result,mx,vis,0);
            
//             if(res.size()==0){
//                 res.push_back({mx,i});
//             }else{                     
//                 reArrangeElements(res,mx,i);                                          
//             }            
//         }
        
//         for(auto it:res){
//             output.push_back(it.second);
//         }
                
//         return output;
//     }

    //BFS based on degree (O(N))
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<=0){
            return {};
        }
        if(n==1){
            return {0};
        }
        int degree[n];
        memset(degree,0,sizeof(degree));
        vector<int> adj[n];
        
        for(auto i:edges){
            degree[i[0]]++;
            degree[i[1]]++;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        deque<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push_back(i);
            }
        }
        
        while(n>2){
            int size=q.size();
            n-=size;
            
            while(size--){
                int front = q.front();q.pop_front();
                for(auto it:adj[front]){
                    degree[it]--;
                    if(degree[it]==1){
                        q.push_back(it);
                    }
                }
            }
        }
        return vector<int>(q.begin(),q.end());
    }
};