class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> s;
        vector<int> result;
        for(int i=nums2.size()-1;i>=0;i--){
            while(s.size()>0&&s.top()<nums2[i]){
                s.pop();
            }
            if(s.empty()){
                mp[nums2[i]]=-1;
            }else{
                mp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        for(int i:nums1){
            result.push_back(mp[i]);
        }
        return result;
    }
};