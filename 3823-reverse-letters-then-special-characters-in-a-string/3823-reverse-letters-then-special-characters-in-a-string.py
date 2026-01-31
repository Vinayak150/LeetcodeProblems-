class Solution:
    def reverseByType(self, s: str) -> str:
        letters = []
        specials = []
        for ch in s:
            if 'a' <= ch <= 'z':
                letters.append(ch)
            else:
                specials.append(ch)

        letters.reverse()
        specials.reverse()

        res =[]
        l =0
        sp =0
        for ch in s:
            if 'a' <= ch <= 'z':
                res.append(letters[l])
                l +=1
            else:
                res.append(specials[sp])
                sp += 1
        return "".join(res)
        