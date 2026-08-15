class Solution:
    def getKey(self, string):
        freq=[0]*26
        for char in string:
            idx = ord(char) - ord('a')
            print(char+" "+str(idx))
            freq[idx] = freq[idx]+1
        res=''
        for i in freq:
            res=res+'*'+str(i)
        return res


    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map={}
        for str in strs:
            key = self.getKey(str)
            print(key)
            if key in map:
                map[key].append(str)
            else:
                map[key]=[]
                map[key].append(str)
        print(map)
        res = []
        for key in map:
            res.append(map[key])
        return res;