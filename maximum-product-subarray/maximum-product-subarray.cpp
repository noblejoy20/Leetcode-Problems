class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int prod=1;
        int mx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            prod*=arr[i];
            mx=max(mx,prod);
            if(prod==0){
                prod=1;
            }
        }
        prod=1;
        for(int j=arr.size()-1;j>=0;j--){
            prod*=arr[j];
            mx=max(mx,prod);
            if(prod==0){
                prod=1;
            }
        }
        return mx;
    }
};