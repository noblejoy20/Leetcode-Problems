class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,leftMax=0,rightMax=0,val=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(leftMax>height[left]){
                    val+=leftMax-height[left];
                }else{
                    leftMax=height[left];
                }
                left++;
            }else{
                if(rightMax>height[right]){
                    val+=rightMax-height[right];
                }else{
                    rightMax=height[right];
                }
                right--;
            }
        }
        return val;
    }
};