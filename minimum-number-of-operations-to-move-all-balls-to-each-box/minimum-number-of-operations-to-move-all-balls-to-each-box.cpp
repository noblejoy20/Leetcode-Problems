class Solution {
public:
    
/* When we say calculating the number of operations for moving all the balls to the left of a box to that bax, say we are at the i th position(or box). This consists of two parts, first dp[i - 1] will give us the number of operations to move all the balls so far till (i - 1) th position and now we have all the balls till the (i - 1) th position in the (i - 1) th position(or box). Then the next part involves moving all those balls in (i - 1) th position to the i th position. Also note the cost of moving a single ball by 1 position is 1. So the recurrence relation becomes:

dp[i] = dp[i - 1] + (1 * balls) where 1 here is the cost of moving a single ball. */

    vector<int> minOperations(string boxes) {
        int left[boxes.length()];
        int right[boxes.length()];
        vector<int> result;
        
        int count=0;
        left[0]=0;
        for(int i=1;i<boxes.length();i++){
            if(boxes[i-1]=='1'){
                count++;
                left[i]=left[i-1]+count;
            }else{
                left[i]=left[i-1]+count;
            }
        }
        count=0;
        right[boxes.length()-1]=0;
        for(int i=boxes.length()-2;i>=0;i--){
            if(boxes[i+1]=='1'){
                count++;
                right[i]=right[i+1]+count;
            }else{
                right[i]=right[i+1]+count;
            }
        }
        for(int i=0;i<boxes.length();i++){
            result.push_back(left[i]+right[i]);
        }
        return result;
    }
};