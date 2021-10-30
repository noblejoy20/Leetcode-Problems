class Solution {
public:
    int dp[1002][1002];
    
    string lps(string str,int n){
       if(str == "") {
          return 0;
        }

        bool arr[n][n];
        memset(arr,false,sizeof(arr));
        int maxLps = 1;
        string maxStr=string(1,str[0]);
        for (int i = 0; i < str.length(); i++) {
          arr[i][i] = true;
        }

        for(int i = n - 2; i >= 0; i--) {
          for(int j = i + 1; j < n; j++) {

            if(str[i] == str[j]) {
              if(arr[i + 1][j - 1] || j - i == 1) {
                arr[i][j] = true;
                  if(maxLps<j-i+1){
                      maxLps=j - i + 1;
                      maxStr=str.substr(i,j-i+1);
                  }
              }
                
            //maxStr=str.substr(i,j-i+1);
            }
          }
        }

        return maxStr;
    }
    string longestPalindrome(string first) {
        memset(dp,-1,sizeof(dp));
        if(first.length()==1){
            return first;
        }
        return lps(first,first.length());
    }
};