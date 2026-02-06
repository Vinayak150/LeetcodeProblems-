class Solution(object):
    def minRemoval(self, nums, k):
        nums.sort()
        n = len(nums)
        maxlen = 1
        j =0
        for i in range(n):
            while j < n and nums[j] <=nums[i]*k:
                j += 1
            cur = j -i
            if cur > maxlen:
                maxlen = cur
        
        return n - maxlen
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        