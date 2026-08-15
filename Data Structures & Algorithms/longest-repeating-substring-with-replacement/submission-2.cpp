class Solution {
public:
    int characterReplacement(string s, int k) {
        int count = 0 ;
        int n = s.length();
        int l = 0;
        int r = 0;
        vector<int> freq(26, 0);
        int res = INT_MIN;
        while(r<n){
            freq[s[r]-'A']++;
            count = max(count, freq[s[r]-'A']);
            // if(count+k < r-l+1){
                
            // }

            while(count+k < r-l+1){
                freq[s[l]-'A']--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }

        return res;
    }
};
