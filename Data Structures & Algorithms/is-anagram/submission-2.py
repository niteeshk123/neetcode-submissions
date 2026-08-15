class Solution:
    def getKey(self, string):
        freq = []
        for i in range(26):
            freq.append(0)
        
        for char in string:
            freq[ord(char)-ord('a')]=freq[ord(char)-ord('a')]+1
        
        res = ''
        for num in freq:
            res=res+str(num)
        return res

    def isAnagram(self, s: str, t: str) -> bool:
        str1 = self.getKey(s)
        str2 = self.getKey(t)
        print(str1)
        print(str2)
        if str1==str2:
            return True
        return False