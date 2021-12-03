class Solution {
public:
    int solve(int curr,vector<int>& freq,vector<string>& words,vector<int>& score){
        //yes
        if(curr==words.size()){
            return 0;
        }
        bool flag=true;
        int currscore=0;
        for(auto it:words[curr]){
            if(freq[it-'a']==0) flag=false;  
            freq[it-'a']--;
            currscore+=score[it-'a'];
        }
        if(flag){
           currscore+= solve(curr+1,freq,words,score);
        }else{
           currscore=0;
        }
        for(auto it:words[curr]){
            freq[it-'a']++;
        }
        //no
        return max(currscore,solve(curr+1,freq,words,score));
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        int ans=0;
        for(auto it:letters){
            freq[it-'a']++;
        }
        return solve(0,freq,words,score);
    }
};