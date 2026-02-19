class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        prevg =0
        currg =1
        r =0
        for i in range(1,len(s)):
            if s[i] ==s[i-1]:
                currg +=1
            else:
                r += min(prevg,currg)
                prevg = currg
                currg = 1
        r += min(prevg,currg)
        return r

        