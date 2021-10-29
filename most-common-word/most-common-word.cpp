class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        set<string> ban(banned.begin(),banned.end());
        transform(p.begin(),p.end(),p.begin(),::tolower);
        unordered_map<string,int> mp;
        int mx=INT_MIN;
        string ans="";
        for(char c:p){
            if(c>='a'&&c<='z'){
                ans+=c;
            }else{
                if(ans.length()>0 && ban.count(ans)==0){
                    mp[ans]++;
                    mx=max(mx,mp[ans]);
                }                
                ans="";
            }                      
        }
        if(ans.length()>0 && ban.count(ans)==0){
            mp[ans]++;
            mx=max(mx,mp[ans]);
        } 
        for(auto it:mp){
            if(it.second==mx){
                return it.first;
            }
        }
        return "";
    }
};