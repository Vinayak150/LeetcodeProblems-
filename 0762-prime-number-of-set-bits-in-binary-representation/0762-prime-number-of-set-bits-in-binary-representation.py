class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        primes ={2,3,5,7,11,13,17,19}
        r=0
        for n in range(left,right+1):
            n1=n
            c=0
            while n >0:
                n=n&(n-1)
                c+=1
            if c in primes:
                r+=1
        return r
        