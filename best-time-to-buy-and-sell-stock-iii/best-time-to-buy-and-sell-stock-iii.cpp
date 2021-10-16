class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftProfit[prices.size()];
        int minSum=prices[0];
        int maxProfit=INT_MIN;
        
        // From left to right calculate at each point how much is the maximum profit that we can make 
        // if we sell on the given day. Hence maintain the previous minimum dip and current profit.
        for(int i=0;i<prices.size();i++){
            int profit=prices[i]-minSum;
            maxProfit=max(maxProfit,profit);
            leftProfit[i]=maxProfit;
            minSum=min(prices[i],minSum);
        }
        int rightProfit[prices.size()];
        int maxSum=prices[prices.size()-1];
        maxProfit=INT_MIN;
        
        // Similarly from right to left, here instead of dip we need to maintain the peak since we are traversing from
        // right to left and calculate the maximum profit.
        for(int i=prices.size()-1;i>=0;i--){
            int profit=maxSum-prices[i];
            maxProfit=max(maxProfit,profit);
            rightProfit[i]=maxProfit;
            maxSum=max(prices[i],maxSum);
        }
        int ans=INT_MIN;
        
        // Lastly we need to find the maximum of the sum of left and right maximum from the two resultant arrays.
        for(int i=0;i<prices.size();i++){
            ans=max(ans,leftProfit[i]+rightProfit[i]);
        }
        return ans;
    }
};