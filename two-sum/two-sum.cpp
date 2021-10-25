class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //O(n^2) Iterate over all possibilities
        //O(nlogn) sort the array and the find the target sum.
        //O(n)
        unordered_map<int,int> s;
        for(int i=0;i<nums.size();i++){
            auto it=s.find(target-nums[i]);
            if(it!=s.end()){
                return vector<int>({it->second,i});
            }else{
                s[nums[i]]=i;
            }
        }
        return {};
    }
};