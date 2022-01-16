class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> dist;
        for(int i=0;i<seats.size();i++){
            if(seats[i]){
                dist.push_back(i);
            }
        }
        int mx=INT_MIN;
        mx=max(mx,dist[0]-0);
        for(int i=1;i<dist.size();i++){
            mx=max(mx,(dist[i]-dist[i-1])/2);
        }
        //cout<<dist.size()-dist[dist.size()-1]-1;
        mx=max(mx,(int)seats.size()-dist[dist.size()-1]-1);
        return mx;
    }
};