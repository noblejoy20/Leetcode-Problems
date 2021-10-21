class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& repository, string customerQuery) {
        set<string> s;
        vector<vector<string>> result;
        for(auto word:repository){
            transform(word.begin(),word.end(),word.begin(),::tolower);
            s.insert(word);
        }
        // for(string t:s){
        //     cout<<t<<" ";
        // }
        for(int i=1;i<=(int)customerQuery.length();i++){
            string temp=customerQuery.substr(0,i);
            //transform(temp.begin(),temp.end(),temp.begin(),::tolower);
            auto it=lower_bound(s.begin(),s.end(),temp);
            vector<string> ans;
            int count=0;
            for(auto start=it;start!=s.end()&&count<3;start++){
                string t=*start;
                //cout<<t<<" ";
                transform(t.begin(),t.end(),t.begin(),::tolower);
                if(t.substr(0,i)==temp){
                    ans.push_back(*start);
                    count++;
                }else{
                    break;
                }            
            }
            result.push_back(ans);

        }
        return result;
    }
};