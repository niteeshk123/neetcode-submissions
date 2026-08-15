class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<int, int> mp;
        int n = s.length();
        int count = 0;
        int l = 0;

        for(int r=0; r<n; r++){
            mp[s[r]]++;
            count = max(count, mp[s[r]]);

            while(r-l+1 - count > k){
                mp[s[l]]--;
                l++;
            }

            res = max(res, r-l+1);
        }

        return res;
    }
};
