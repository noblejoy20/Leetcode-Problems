class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> result;string word;
        unordered_map<string,vector<int>> sentence;
        unordered_map<char,vector<int>> pat;
        
        for(int i=0;i<pattern.length();i++){
            pat[pattern[i]].push_back(i);
        }
        
        stringstream ss(s);
        while(ss>>word){
            result.push_back(word);
        }
        
        if(result.size()!=pattern.size()){
            return false;
        }
        
        for(int j=0;j<result.size();j++){
            sentence[result[j]].push_back(j);
        }
        
        for(int i=0;i<result.size();i++){
            auto patIdx=pat[pattern[i]];
            auto sentIdx=sentence[result[i]];
            if(patIdx.size()==sentIdx.size()){
                for(int k=0;k<patIdx.size();k++){
                    if(patIdx[k]!=sentIdx[k]){
                        return false;
                    }
                }
            }else{
                return false;
            }
        }
        return true;
        
    }
};