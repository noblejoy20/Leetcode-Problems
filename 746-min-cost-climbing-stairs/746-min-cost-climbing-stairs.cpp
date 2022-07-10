class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=cost[0];
        int b=cost[1];
        int c=0;
        for(int i=2;i<=cost.size();i++){
            c=(i<cost.size()?cost[i]:0)+min(a,b);
            a=b;
            b=c;
        }
        return c;
    }
};