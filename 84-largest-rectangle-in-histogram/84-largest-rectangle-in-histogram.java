class Solution {
    public int[] nsr(int[] heights){
        Stack<Integer> stk = new Stack<>();
        int[] arr=new int[heights.length];
        for(int i=heights.length-1;i>=0;i--){
            while(!stk.isEmpty() && heights[stk.peek()]>=heights[i]){
                stk.pop();
            }
            if(stk.isEmpty()){
                arr[i]=heights.length;
            }else{
                arr[i]=stk.peek();
            }
            
            stk.push(i);
        }
        return arr;
    }
    public int[] nsl(int[] heights){
        Stack<Integer> stk = new Stack<>();
        int[] arr=new int[heights.length];
        for(int i=0;i<heights.length;i++){
            while(!stk.isEmpty() && heights[stk.peek()]>=heights[i]){
                stk.pop();
            }
            if(stk.isEmpty()){
                arr[i]=-1;
            }else{
                arr[i]=stk.peek();
            }
            
            stk.push(i);
        }
        return arr;
    }
    public int largestRectangleArea(int[] heights) {
        int[] left=nsl(heights);
        int[] right=nsr(heights);
        int max=Integer.MIN_VALUE;
        for(int i=0;i<heights.length;i++){
            int val=(right[i]-left[i]-1)*heights[i];
            max=Integer.max(max,val);
        }
        return max;
    }
}