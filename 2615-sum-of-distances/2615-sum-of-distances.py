class Solution:
    def distance(self, nums):
        mp =defaultdict(list)
        for i, val in enumerate(nums):
            mp[val].append(i)
        n=len(nums)
        res=[0]*n

        for val in mp:
            p=mp[val]
            pr=[0]*(len(p)+1)
            for i in range(len(p)):
                pr[i+1]=pr[i]+p[i]
            for k in range(len(p)):
                i=p[k]
                lc=k
                ls=pr[k]
                l=i*lc-ls
                rc=len(p)-k-1
                rs=pr[-1]-pr[k+1]

                r=rs-i*rc
                res[i]=l+r
        return res


        