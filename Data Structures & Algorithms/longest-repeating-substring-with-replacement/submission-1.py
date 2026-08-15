class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        r = 0
        length = 0
        n = len(s)
        freq = [0]*26
        count = 0
        while(r<n):
            idx = ord(s[r])-ord('A')
            freq[idx]+=1
            count = max(count, freq[idx])
            while(r-l+1 - count > k):
                idx1 = ord(s[l])-ord('A')
                freq[idx1]-=1
                l+=1
            length = max(length, r-l+1)
            r+=1
        return length