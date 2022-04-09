typedef pair<int,int> pp;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto it:nums){
            mp[it]++;
        }
        vector<vector<int>> v(10003,vector<int>{});
        for(auto it:mp){
            v[it.second].push_back(it.first);
        }
        for(int i=v.size()-1;i>=0;i--){
            if(v[i].size()>0){
                for(auto it:v[i]){
                    ans.push_back(it);
                    k--;
                    if(k==0) return ans;
                }
            }
            
        }
        return {};
    }
};