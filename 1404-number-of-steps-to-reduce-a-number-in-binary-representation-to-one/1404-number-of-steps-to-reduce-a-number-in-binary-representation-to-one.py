class Solution:
    def numSteps(self, s: str) -> int:
        n =len(s)
        step=0
        carry =0
        for i in range(n-1,0,-1):
            b = int(s[i])+carry
            if b % 2 ==0:
                step+=1
            else:
                step += 2
                carry =1
        return step+carry
        