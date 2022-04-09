typedef pair<int,int> pp;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<pp> pq;
        
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};