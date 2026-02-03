class Solution:
    def isTrionic(self, nums):
        n = len(nums)
        if n < 4:
            return False

        incL =[False] * n
        incR =[False] * n
        incL[0] = True
        for i in range(1,n):
            incL[i] = incL[i-1] and nums[i-1]<nums[i]
        incR[n-1]=True
        for i in range( n-2, -1,-1):
                incR[i] =incR[i+1] and nums[i]< nums[i+1]
            
        for p in range(1, n-2):
                if not incL[p] or nums[p]<= nums[p+1]:
                    continue
                
                q = p+1

                while q < n-1 and nums[q-1] > nums[q]:

                    if incR[q]:
                        return True

                    q += 1
        return False
        