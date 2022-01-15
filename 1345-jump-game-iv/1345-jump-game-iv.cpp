class Solution {
public:
    int bfs(int start,vector<int>& vis,unordered_map<int,vector<int>>& mp,vector<int>& arr){
        queue<int> q;
        q.push(start);
        vis[start]=1;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int val=q.front();q.pop();
                if(val==arr.size()-1) return steps;
                vector<int>& next = mp[arr[val]];
                next.push_back(val-1);next.push_back(val+1);
                for(auto it:next){
                    
                    if(it>=0 && it<arr.size() && !vis[it]){
                        vis[it]=true;
                        q.push(it);
                    }
                }
                next.clear();
            }
            steps++;
        }
        return 0;
    }
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> visited(arr.size()+1,0);
        
        return bfs(0,visited,mp,arr);
    }
};