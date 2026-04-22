class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        r=[]
        for q in queries:
            found=False
            for  d in dictionary:
                m=0
                for i in range(len(q)):
                    if q[i]!=d[i]:
                        m+=1
                        if m >2:
                            break
                if m <= 2:
                    found=True
                    break

            if found:
                r.append(q)

        return r
        