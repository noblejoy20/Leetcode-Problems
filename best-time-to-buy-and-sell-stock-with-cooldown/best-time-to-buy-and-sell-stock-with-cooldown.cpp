class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        //Maintain three states ,i.e, buy, sell and cooldown
        int dp[n][3];
        
        dp[0][0]=-prices[0];//first day buy state (if you buy then you will be in debt of -prices[0])
        dp[0][1]=0; //first day sell state (you cannot sell anything on first day)
        dp[0][2]=0; //first day cooldown state (you will not have previous sold state to cooldown)
        
        //Start from day 1
        for(int i=1;i<prices.size();i++){
            // Today's bought state will be the maximum of the (previous bought state and cooldown - buy today)
            dp[i][0]=max(dp[i-1][0],dp[i-1][2]-prices[i]);
            
            // Today's sold state will be the maximum of (previous bought state + sell today and previous sold state)
            dp[i][1]=max(dp[i-1][0]+prices[i],dp[i-1][1]);
            
            // Today's cooldown state will be the maximum of (previous cooldown state and previous sold state)
            dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        }
        
        // Return the final profit in sold state
        return dp[n-1][1];
    }
};