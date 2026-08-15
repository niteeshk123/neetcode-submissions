class Solution:
    def getkey(self, s):
        l=[0]*26
        for c in s:
            l[ord(c)-ord('a')]+=1
        key=''
        for c in l:
            key=key+str(c)+','
        return key[:-1]
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map={}
        for s in strs:
            key = self.getkey(s)
            if key in map:
                map[key].append(s)
            else:
                map[key]=[]
                map[key].append(s)
        res = []
        for key in map:
            res.append(map[key])
        return res