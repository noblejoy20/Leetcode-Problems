class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        bool flag=false;
        int count=0,idx=0;
        
        for(auto &w:wordList){
            if(w!=endWord){
                words.insert(w);
            }else{
                flag=true;
            }
        }
        
        if(!flag) return 0;
        queue<string> q;
        q.push(endWord);
         
        while(!q.empty()){
            int size = q.size();
            count++;
            while(size--){
                string val = q.front();q.pop();
                words.erase(val);
                for(int k=idx;k<val.length();k++){
                    string res=val;
                    for(int i=0;i<26;i++){
                        res[k]=char(i+'a');
                        if(res==beginWord) return count+1;
                        if(words.count(res)){
                            q.push(res);
                            //cout<<res<<" ";
                        } 
                    }
                }
            }
           //cout<<"\n";
        }
        return 0;
    }
};