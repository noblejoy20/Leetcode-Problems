class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        for(auto it:word){
            if(isupper(it)) count++;
        }
        if(count==1){
            return isupper(word[0]);
        }else if(count == word.length()){
            return true;
        }else if(count==0){
            return true;
        }
        return false;
    }
};