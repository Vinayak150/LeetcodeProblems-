class Solution:
    def minOperations(self, s: str) -> int:
        n=len(s)
        start0 =0
        start1 =0
        for i in range(n):
            if i%2==0:
                ex0='0'
                ex1='1'
            else:
                ex0 ='1'
                ex1 ='0'
            if s[i]!= ex0:
                start0 +=1
            if s[i]!=ex1:
                start1 +=1
        return min(start0,start1)
        
        