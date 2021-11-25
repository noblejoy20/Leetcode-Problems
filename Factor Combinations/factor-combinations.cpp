class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a 2D array
     */
     vector<vector<int>> result;
     void getFactorsHelper(int n,int start,vector<int>& factors){
       if(n==1){
           result.push_back(factors);
           return;
       }
       cout<<"\n";
       for(int i=start;i<=n;i++){
            if(n%i==0){
                factors.push_back(i);
                getFactorsHelper(n/i,i,factors);
                factors.pop_back();
            }
        }  
     }
    vector<vector<int>> getFactors(int n) {
        // write your code here
        vector<int> ans;
        for(int i=2;i<n;i++){
            if(n%i==0){
                ans.push_back(i);
                getFactorsHelper(n/i,i,ans);
                ans.pop_back();
            }
        }
        return result;
    }
};
