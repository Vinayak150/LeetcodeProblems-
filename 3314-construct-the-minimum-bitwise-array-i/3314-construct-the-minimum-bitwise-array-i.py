class Solution:
    def minBitwiseArray(self, nums):
        r = []
        for n in nums:
            if n ==2: r.append(-1); continue
            b =1
            while n&b: b<<=1
            r.append(n-(b>>1))
        return r
