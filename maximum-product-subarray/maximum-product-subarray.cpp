class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int mx=INT_MIN;
        for(auto it:nums){
            prod*=it;
            mx=max(mx,prod);
            if(prod==0){
                prod=1;
            }
        }
        //cout<<mx;
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            mx=max(mx,prod);
            if(prod==0){
                prod=1;
            }
        }
        return mx;
    }
};