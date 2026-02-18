class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pr= n & 1;
        n = n >> 1;
        while(n>0){
            int cur = n&1;
            if(cur == pr){
                return false;
            }
            pr = cur;
            n=n>>1;

        }
        return true;
    }
};