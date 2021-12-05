class Solution {
public:
    int lowerbound(vector<int>& arr,int x){
        int i=0,j=arr.size()-1;
        int ans=arr.size();
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]>=x){
                ans=mid;
                j=mid-1;
            }else {
                i=mid+1;
            }
        }
        return ans;
        
    }
    int closest(vector<int>& arr,int x){
        int ans=lowerbound(arr,x);
        if(ans==arr.size())
        { 
            return arr[ans-1];
        }
        else if(ans==0) 
        {
            return arr[0];
        }
        else if(abs(x-arr[ans])<abs(x-arr[ans-1]))
        {
            return arr[ans];
        }
        else{
            return arr[ans-1];
        }
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int mx=INT_MIN;
        for(int i=0;i<houses.size();i++){
            mx=max(mx,abs(closest(heaters,houses[i])-houses[i]));
        }
        return mx;
    }
};