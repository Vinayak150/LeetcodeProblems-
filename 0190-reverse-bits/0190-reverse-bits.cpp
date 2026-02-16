class Solution {
public:
    int reverseBits(int n) {
        unsigned int r =0;
        for(int i =0;i<32;i++){
            int l = n&1;
            r =r<<1;
            r=r|l;
            n=n>>1;
        }
        return r;
        
    }
};