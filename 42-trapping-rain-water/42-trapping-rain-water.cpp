class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> val;
        int mx=height[0];
        for(auto it:height){
            mx=max(mx,it);
            val.push_back(mx);
        }
         mx=height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            mx=max(height[i],mx);
            val[i]=min(val[i],mx);
        }
        int ans=0;
        for(int i=0;i<val.size();i++){
            ans+=val[i]-height[i];
        }
        return ans;
    }
};