class Solution:
    def binaryGap(self, n: int) -> int:
        last =-1
        maxd =0
        pos =0
        while n >0:
            if n & 1:
                if last != -1:
                    maxd =max(maxd,pos - last)
                last = pos
            n= n>>1

            pos+=1
        return maxd
            