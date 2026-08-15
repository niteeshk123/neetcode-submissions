class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        vector<int> freq(256, 0);
        int n = s.length();
        if(n==0 || n==1){
            return n;
        }
        int res = INT_MIN;
        while(r<n){
            freq[s[r]]++;
            if(freq[s[r]]>1){
                res = max(res, r-l);
            }

            while(freq[s[r]]>1){
                freq[s[l]]--;
                l++;
            }
            r++;
        }

        res = max(res, r-l);

        return res;
    }
};
