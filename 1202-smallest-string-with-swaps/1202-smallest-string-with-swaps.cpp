class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> adj[s.length()];
        for(auto it:pairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(s.length(),false);
        
        queue<int> q;
        
        
        for(int i=0;i<s.length();i++){
            if(!vis[i] && adj[i].size()>0){
                q.push(i);
                vis[i]=true;
                vector<int> temp;
                while(!q.empty()){                    
                    int val = q.front();q.pop();
                    temp.push_back(val);
                    for(auto it:adj[val]){
                        if(!vis[it]){
                            vis[it]=true;
                            q.push(it);
                        }
                    }
                }
                string res="";
                sort(temp.begin(),temp.end());
                for(auto it:temp){
                    res+=s[it];
                }
                sort(res.begin(),res.end());
                for(int i=0;i<temp.size();i++){
                    s[temp[i]]=res[i];
                }
            }
        }
        return s;
    }
};