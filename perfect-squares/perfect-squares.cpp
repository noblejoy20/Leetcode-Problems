// Link: https://leetcode.com/problems/perfect-squares/discuss/1520690/Recursion%2BMemoization-greaterBottom-Up-DP-greaterBFS-queue
class Solution {
public:
        //BFS
        int numSquaresBFS(int n) {
            queue<int> q;
            q.push(n);
            int count=0;
            while(!q.empty()){
                int size=q.size();
                while(size--){
                    int temp=q.front();
                    q.pop();
                    for(int i=1;i*i<=temp;i++){
                        if(temp-(i*i)>0){
                            q.push(temp-(i*i));
                        }else if(temp-(i*i)==0){
                            count++;
                            return count;
                        }else{
                            break;
                        }
                    }
                }
                count++;
            }
            return 0;
        }
        
        //DP-Memoization
        int dp[10002];
        int solve(int n){
            //cout<<n<<"\n";
            if(n==0){
                return 0;
            }
            if(n<0){
                return INT_MAX-1;
            }
            if(dp[n]!=-1){
                return dp[n];
            }
            int mx=INT_MAX;
            for(int i=1;i*i<=n;i++){
                int res=1+solve(n-(i*i));
                mx=min(res,mx);

            }

            dp[n]=mx;
            return mx;
        }
        int numSquaresMemo(int n){
            memset(dp,-1,sizeof(dp));
            return solve(n);
        }
    
       //Bottom-up  
       int numSquares(int n){
           int dp[10002]={0};
           for(int i=1;i<=n;i++){
               int mn=INT_MAX;
               for(int j=1;j*j<=i;j++){
                   mn=min(mn,dp[i-(j*j)]);
                   dp[i]=1+mn;
               }
           }
           return dp[n];
       }
};