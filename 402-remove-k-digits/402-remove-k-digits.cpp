class Solution {
public:
    string removeKdigits(string nums, int k) {
        deque<char> q;
        string res="";
        q.push_back(nums[0]);
        for(int i=1;i<nums.length();i++){
            while(!q.empty() && q.back()>nums[i]){
                if(k==0) break;
                q.pop_back();
                k--;
            }
            if(q.empty() && nums[i]=='0'){
                continue;
            }
            q.push_back(nums[i]);
        }

        if(q.empty() || k> q.size()) return string(1,'0');
        
        while(k--){
            q.pop_back();
        }       
        
        while(!q.empty()){
            res+=q.front();
            q.pop_front();
        }
        
        return res==""?string(1,'0'):res;
    }
};