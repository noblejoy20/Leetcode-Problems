class Solution {
public:
    vector<vector<int>> ans;
    void combineHelper(int n,int start,int k,vector<int>& v){ 
        
        if(start==n){
            if(v.size()==k){
                ans.push_back(v);
            }
            return;
        }

        
        combineHelper(n,start+1,k,v);
        v.push_back(start);
        combineHelper(n,start+1,k,v);
        v.pop_back();                
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        combineHelper(n+1,1,k,v);
        return ans;
    }
};