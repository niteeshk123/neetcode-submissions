class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int left = 0;
        int right = 0;
        int res = 0;
        while(right<s.length()){
            freq[s[right]]++;
            if(freq[s[right]]>1){
                res = max(right-left, res);
            }
            
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            right++;
        }

        res = max(res, right-left);
        return res;
    }
};
