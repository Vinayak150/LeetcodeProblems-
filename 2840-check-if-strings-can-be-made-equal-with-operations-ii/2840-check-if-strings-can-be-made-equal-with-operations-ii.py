from collections import Counter

class Solution:
    def checkStrings(self, s1,s2):
        
        
        even_s1 = []
        odd_s1 = []
        even_s2 = []
        odd_s2 = []
        
        for i in range(len(s1)):
            if i % 2 == 0:
                even_s1.append(s1[i])
                even_s2.append(s2[i])
            else:
                odd_s1.append(s1[i])
                odd_s2.append(s2[i])
        
        
        return Counter(even_s1) == Counter(even_s2) and \
               Counter(odd_s1) == Counter(odd_s2)