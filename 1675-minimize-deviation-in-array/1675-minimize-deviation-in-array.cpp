class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int best=INT_MAX;
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());        
        priority_queue<int,vector<int>,greater<int>> res(nums.begin(),nums.end());
        //cout<<mx<<" "<<res.top();
        best=min(best,mx-res.top());
        while(res.top()%2==1){
            int val=res.top();
            res.pop();
            mx=max(mx,val*2);
            res.push(val*2);
            cout<<best<<" ";
            best=min(best,mx-res.top());
        }
       
        mn=res.top();
        priority_queue<int> ans;
         while(!res.empty()){
            ans.push(res.top());res.pop();
        }
        while(ans.top()%2==0){
            int val=ans.top();
            ans.pop();
            mn=min(mn,val/2);          
            ans.push(val/2);
            best=min(best,ans.top()-mn);
        }
        
        
        
        
        return best;
    }
};