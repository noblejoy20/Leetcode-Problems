class Solution {
    public int calcFloor(int[] arr,int x){
        int left=0,right=arr.length-1,ans=-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(arr[mid]<=x){
                ans = mid;
                left = mid+1;
            }else {
                right = mid-1;
            }
        }
        return ans;
    }
    public int calcCeil(int[] arr,int x){
        int left=0,right=arr.length-1,ans=arr.length;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(arr[mid]<=x){                
                left = mid+1;
            }else {
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int floor = calcFloor(arr,x);
        int ceil = calcCeil(arr,x);
        List<Integer> ans=new ArrayList<>();
        while(k>0 && floor>=0 && ceil<arr.length){            
            if(Math.abs(x-arr[floor])<=Math.abs(x-arr[ceil])){
                ans.add(arr[floor]);
                floor--;
            }else{
                ans.add(arr[ceil]);
                ceil++;
            }
            k--;
        }
        while(k>0 && floor>=0){
            ans.add(arr[floor]);
            floor--;
            k--;
            
        }
        while(k>0 && ceil<arr.length){            
            ans.add(arr[ceil]);
            ceil++;    
            k--;
        }
        Collections.sort(ans);
         return ans;
    }
}