class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> dist;
        int pos=-1,mx=INT_MIN;
        for(int i=0;i<seats.size();i++){
            if(seats[i]){
                if(pos==-1){
                    mx=max(mx,i);
                }else{
                    mx=max(mx,(i-pos)/2);
                }                
                pos=i;
            }
        }
        mx=max(mx,(int)seats.size()-pos-1);
        return mx;
    }
};