class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int arr[n][n];
        memset(arr,0,sizeof(arr));
        for(auto t:trust){
            arr[t[0]-1][t[1]-1]=1;
        }
        stack<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            int first = q.top();q.pop();
            int second = q.top();q.pop();
            if(arr[first-1][second-1]){
                q.push(second);
            }else{
                q.push(first);
            }
        }
        int val = q.top();
        for(int i=0;i<n;i++){
            //cout<<arr[i][val-1]<<" ";
            if(i!=val-1 && (arr[i][val-1]!=1||arr[val-1][i]!=0)){
                return -1;
            }
        }
        return val;
    }
};