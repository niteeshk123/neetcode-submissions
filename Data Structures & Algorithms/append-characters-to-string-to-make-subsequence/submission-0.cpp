class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0;
        int j = 0;
        for(i=0; i<n; i++){
            if(s[i]==t[j]){
                j++;
            }
        }

        return m-j;
    }
};