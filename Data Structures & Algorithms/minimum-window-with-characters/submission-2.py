class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l = 0
        r = 0
        freq_t = {}
        for c in t:
            if c not in freq_t:
                freq_t[c]=0
            freq_t[c]+=1
        
        count = 0
        temp_freq_s = {}
        res = 10e9
        res_s = ''
        for i,c in enumerate(s):
            if c in freq_t:
                if c not in temp_freq_s:
                    count+=1
                    temp_freq_s[c]=0
                elif temp_freq_s[c] < freq_t[c]:
                    count+=1
                
                temp_freq_s[c]+=1
                # print(c,"----",count,"----",len(t))
                if count==len(t):
                    r = i
                    # print(s[l:r+1])
                    while l < r:
                        if s[l] not in freq_t:
                            l+=1
                        elif s[l] in freq_t and temp_freq_s[s[l]]>freq_t[s[l]]:
                            temp_freq_s[s[l]]-=1
                            l+=1
                        else:
                            break
                    if res >= r - l +1:
                        res_s = s[l:r+1]
                        # print("res_s",res_s)
                        res = r - l + 1
                    temp_freq_s[s[l]]-=1
                    count-=1
                    l+=1
            
        return res_s