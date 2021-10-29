class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k, int count=0) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>> result;
        for(auto point:points){
            pq.push({abs((point[0]-0)*(point[0]-0)+(point[1]-0)*(point[1]-0)),count++});
        }
        count=0;
        while(!pq.empty() && count<k){
            auto ans=pq.top();pq.pop();
            result.push_back(points[ans.second]);
            count++;
        }
        return result;
    }
};