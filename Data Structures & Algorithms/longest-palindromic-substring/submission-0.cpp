class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        int res_i = -1;
        int res_len = 0;
        for(int i=0; i<n;i++){
            int l = i;
            int r = i;

            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > res_len){
                    res_len = r-l+1;
                    res_i = l;
                }
                l--;
                r++;
            }
            l=i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > res_len){
                    res_len = r-l+1;
                    res_i = l;
                }
                r++;
                l--;
            }
        }

        return s.substr(res_i, res_len);
    }
};
