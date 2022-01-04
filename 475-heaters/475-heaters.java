class Solution {
    public int search(int[] heaters,int target){
        int left=0;int right=heaters.length-1;
        int floor=0,ceil=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(heaters[mid]==target){
                return 0;
            }else if(heaters[mid]>target){
                floor=mid;
                right=mid-1;
            }else{
                ceil=mid;
                left=mid+1;
            }
        }
        if(Math.abs(heaters[floor]-target)>Math.abs(heaters[ceil]-target)){
                return Math.abs(heaters[ceil]-target);
            }
        return Math.abs(heaters[floor]-target);
    }
    public int findRadius(int[] houses, int[] heaters) {
        int n = houses.length;
        Arrays.sort(heaters);
        int mx=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            mx=Math.max(mx,search(heaters,houses[i]));
        }
        return mx;
    }
}