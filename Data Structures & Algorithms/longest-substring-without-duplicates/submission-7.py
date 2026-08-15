class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        l = 0
        r = 0
        n = len(s)
        if(n==1 or n==0):
            return n
        freq = [0]*256
        while(r<n):
            idx = ord(s[r])
            freq[idx]+=1
            # print("--- r"+s[r])
            while(freq[idx]>1):
                # print("=== l"+s[l])
                idx1 = ord(s[l])
                freq[idx1]-=1
                l+=1
            length=max(length, r-l+1)
            r+=1
        return length