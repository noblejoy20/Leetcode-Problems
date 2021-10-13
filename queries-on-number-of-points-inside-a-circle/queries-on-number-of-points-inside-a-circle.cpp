class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& sp, vector<vector<int>>& queries) {
        int n=queries.size();
        sort(begin(sp),end(sp)); // sort the points by x coordinates
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            
            // get lower bound for [center - radius]
            
            auto it=lower_bound(begin(sp),end(sp),vector<int>{queries[i][0]-queries[i][2],0}); 
            int x=queries[i][0],y=queries[i][1],r=queries[i][2];
            int count=0;
            
            // iterate from [center - radius] to [center + radius] range and count the points
            // reduces search space from O(n) ---> O([center - radius] to [center + radius])
            for(auto start=it;start!=sp.end()&&(*start)[0]<=queries[i][0]+queries[i][2];start++){
                if((x-(*start)[0])*(x-(*start)[0])+(y-(*start)[1])*(y-(*start)[1])<=r*r){
                    count++;
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};