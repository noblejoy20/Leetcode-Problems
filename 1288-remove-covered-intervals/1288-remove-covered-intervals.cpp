class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals,int count = 1) {
        stack<vector<int>> stk;
        sort(intervals.begin(),intervals.end(),[&](vector<int>& a,vector<int>& b){
            return a[1]==b[1]?a[0]>b[0]:a[1]<b[1];
        });
        for(int i=intervals.size()-2;i>=0;i--){
            auto temp = intervals[i+1];
            if(temp[0]>intervals[i][0]||temp[1]<intervals[i][1]){
                count++;
            }else{
                intervals[i][0] = temp[0];
                intervals[i][1] = temp[1];
            }  
        }
        return count;
    }
};