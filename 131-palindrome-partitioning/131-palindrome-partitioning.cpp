class Solution {
public:
    vector<vector<string>> ans;
    bool isPalin(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void solve(string s,vector<string>& res){
      if(s==""){
          ans.push_back(res);
          return;
      }
      for(int k=1;k<=s.length();k++)
      {
          string temp=s.substr(0,k);
          if(isPalin(temp)){
              res.push_back(temp);
              solve(s.substr(k),res);
              res.pop_back();
          }
      } 
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        solve(s,res);
        return ans;
    }
};