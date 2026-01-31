class Solution:
    def longestSubsequence(self, nums):
        from bisect import bisect_left

        ans = 0

        for b in range(31):
            lis = []
            for x in nums:
                if (x >> b) & 1:
                    i = bisect_left(lis, x)
                    if i == len(lis):
                        lis.append(x)
                    else:
                        lis[i] = x
            ans = max(ans, len(lis))

        return ans
