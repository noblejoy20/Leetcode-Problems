class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        stack<vector<int>> stk;
        sort(intervals.begin(),intervals.end(),[&](vector<int>& a,vector<int>& b){
            return a[1]==b[1]?a[0]>b[0]:a[1]<b[1];
        });
        for(int i=intervals.size()-1;i>=0;i--){
            if(!stk.empty()){
                auto temp = stk.top();
                if(temp[0]>intervals[i][0]||temp[1]<intervals[i][1]){
                    stk.push(intervals[i]);
                }
            }else{
                stk.push(intervals[i]);
            }
        }
        return stk.size();
    }
};