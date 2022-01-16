class Solution {
public:
    int maxDistToClosest(vector<int>& seats,int pos=-1,int mx=INT_MIN) {
        for(int i=0;i<=seats.size();i++){
            if(i<seats.size() && seats[i]){
                mx=pos==-1?max(mx,i):max(mx,(i-pos)/2);               
                pos=i;
            }else if(i==seats.size()){
                mx=max(mx,i-pos-1);
            }
        }
        return mx;
    }
};