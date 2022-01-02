class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int mx=INT_MIN,secmx=INT_MIN;
        for(int i=0;i<time.size();i++){
            if(time[i]>mx){
                secmx=mx;
                mx=time[i];
            }else if(time[i]>secmx){
                secmx=time[i];
            }
        }
        int count=0;
        unordered_map<int,int> keys;
        for(auto it:time){
            if(keys.size()>0){
                for(int i=60;i<=mx+secmx;i+=60){
                    if(i-it>0 && keys.count(i-it)){
                        cout<<"hi";
                        count+=keys[i-it];
                    }
                }
            }
            keys[it]++;          
        }
        return count;
        
    }
};