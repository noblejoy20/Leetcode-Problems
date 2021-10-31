class Solution {
public:
    // calculate next greater element
    vector<int> solve(vector<int>& nums){
        stack<int> stk;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            while(!stk.empty() && nums[stk.top()]<nums[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans[i]=nums.size();
            }else{
                ans[i]=stk.top();
            }
            stk.push(i);
        }
        return ans;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        vector<int> nge=solve(nums);
        
        //maintain a previous window maximum.
        int prevWinMaxIdx=0;
        for(int i=0;i<=nums.size()-k;i++){
            int curr;
            
            //set current pointer to previous window maximum if it lies in range else start from current range.
            if(prevWinMaxIdx>=i&&prevWinMaxIdx<i+k){
                curr=prevWinMaxIdx;
            }else{
                curr=i;
            }
            
            //update the maximum element in current window.
            while(nge[curr]<i+k){
                curr=nge[curr];
            }
            prevWinMaxIdx=curr;
            
            //push the maximum element in current range.
            ans.push_back(nums[curr]);
        }
        return ans;
    }
};