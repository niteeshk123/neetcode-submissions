class Solution:

    def encode(self, strs: List[str]) -> str:
        enc = ''
        for s in strs:
            enc+=str(len(s))+'#'+s
        return enc
    def decode(self, s: str) -> List[str]:
        dec = []
        i =0
        j=0
        while i<len(s):
            num = 0
            while '0'<=s[i] and s[i]<='9':
                num=(num*10)+(ord(s[i])-ord('0'))
                i+=1
            i+=1
            temp=''
            for j in range(num):
                temp+=s[i]
                i+=1
            dec.append(temp)
        return dec