class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n==0:
            return 1
        r =0
        b=1
        while n>0:
            o =n&1
            f =1-o
            if f:
                r|=b
            n>>=1
            b<<=1
        return r