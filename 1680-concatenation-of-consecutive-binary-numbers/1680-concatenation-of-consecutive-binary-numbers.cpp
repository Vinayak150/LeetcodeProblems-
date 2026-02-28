class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD =1000000007LL;
        long long res =0;
        int bitlength =0;
        for(int i=1;i<=n;i++){
            if((i &(i-1))==0){
               bitlength++;
        }
            res=(res<< bitlength)% MOD;
            res=(res + i)% MOD;
        }
        return (int)res;
        
    }
};