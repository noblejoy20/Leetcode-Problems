class Solution {
public:
    int partition(vector<vector<int>>& result,int pivot,int lo,int hi){
        int i=lo,j=lo;
        while(i<=hi){
            if(result[i][0]<=pivot){
                swap(result[i],result[j]);
                i++;j++;
            }else{
                i++;
            }
        }
        return j-1;
    }
    int quickSelect(vector<vector<int>>& result,int lo,int hi,int k){
        if(lo<=hi){
            int pi=partition(result,result[hi][0],lo,hi);
            if(pi==k){
                return pi;
            }else if(k<pi){
                return quickSelect(result,lo,pi-1,k);
            }else{
                return quickSelect(result,pi+1,hi,k);
            }
        }
        return hi+1;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k, int count=0) {
        vector<vector<int>> result,ans;
        for(auto point:points){
            result.push_back(vector<int>({abs((point[0]-0)*(point[0]-0)+(point[1]-0)*(point[1]-0)),count++}));
        }
        int pos=quickSelect(result,0,result.size()-1,k);
        for(int i=0;i<pos;i++){
            ans.push_back(points[result[i][1]]);
        }
        return ans;
    }
};