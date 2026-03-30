class Solution:
    def checkStrings(self, s1,s2):
        
        even = [0] * 26
        odd = [0] * 26

        for i in range(len(s1)):
            if i % 2 == 0:
                even[ord(s1[i]) - 97] += 1
                even[ord(s2[i]) - 97] -= 1
            else:
                odd[ord(s1[i]) - 97] += 1
                odd[ord(s2[i]) - 97] -= 1

        return all(x == 0 for x in even) and all(x == 0 for x in odd)