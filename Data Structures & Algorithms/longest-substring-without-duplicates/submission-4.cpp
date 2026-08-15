class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int count = 0;
        int n = s.length();
        int start = 0;
        for(int i=0; i<n; i++){
            freq[s[i]]++;
            if(freq[s[i]]>1){
                count = max(count, i-start);
                while(freq[s[i]]>1){
                    freq[s[start]]--;
                    start++;
                }
            }
        }
        count = max(count, n-start);
        return count;
    }
};
