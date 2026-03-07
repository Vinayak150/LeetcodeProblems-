class Solution:
    def minFlips(self, s: str) -> int:
        n =len(s)
        alt1=""
        alt2 =""
        doubled =s+s
        for i in range(2*n):
            if i%2==0:
                alt1 +='0'
                alt2 +='1'
            else:
                alt1 += '1'
                alt2+= '0'
        dif1=0
        dif2 =0
        l=0
        a=float('inf')
        for right in range(2*n):
            if doubled[right]!= alt1[right]:
                dif1+=1
            if doubled[right]!=alt2[right]:
                dif2+=1
            if right - l +1 >n:
                if doubled[l]!= alt1[l]:
                    dif1-=1
                if doubled[l]!=alt2[l]:
                    dif2-=1
                l+=1

            if right -l +1 ==n:
                a =min(a,dif1,dif2)
        return a