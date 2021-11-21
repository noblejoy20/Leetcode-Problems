class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){ return 1; } double sum=myPow(x,n/2);
        return n>0?(n&1?x*sum*sum:sum*sum):abs(n)&1?(1/x)*sum*sum:sum*sum;        
    }
};