class Solution {
public:
    vector<vector<string>> ans;
    bool isPalin(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void solve(string& s,vector<string>& res,int l,int r){
      if(l==r){
          ans.push_back(res);
          return;
      }
      for(int k=l;k<r;k++)
      {
          if(isPalin(s,l,k)){
              res.push_back(s.substr(l,k-l+1));
              solve(s,res,k+1,r);
              res.pop_back();
          }
      } 
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        solve(s,res,0,s.length());
        return ans;
    }
};