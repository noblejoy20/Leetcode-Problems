class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int prod=0;
        int mx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            prod+=arr[i];
            mx=max(mx,prod);
            if(prod<0){
                prod=0;
            }
        }
        prod=0;
        for(int j=arr.size()-1;j>=0;j--){
            prod+=arr[j];
            mx=max(mx,prod);
            if(prod<0){
                prod=0;
            }
        }
        return mx;
    }
};