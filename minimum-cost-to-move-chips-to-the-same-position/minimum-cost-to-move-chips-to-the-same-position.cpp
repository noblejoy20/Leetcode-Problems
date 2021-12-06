class Solution {
public:
    int minCostToMoveChips(vector<int>& p) {
        int odd=0;
        int even=0;
        for(int i=0;i<p.size();i++){
            if(p[i]&1){
                odd+=1;
            }else{
                even+=1;
            }
        }
        return min(odd,even);
    }
};