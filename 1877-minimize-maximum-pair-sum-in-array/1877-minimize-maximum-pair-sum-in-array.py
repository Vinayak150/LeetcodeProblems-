class Solution:
    def minPairSum(self, nums):
        nums.sort()
        l=0
        r = len(nums) -1
        max_pair_sum = 0
        while l < r:
            pair_sum = nums[l]+ nums[r]
            max_pair_sum = max(max_pair_sum,pair_sum)
            l += 1
            r-= 1
        return max_pair_sum
        