class Solution {
public:
    int bitwiseComplement(int n) {
        int test=0;
        int num=n;
        do{
            num>>=1;
            test++;
        }while(num);
        return n ^ (int)(pow(2,test)-1);
    }
};