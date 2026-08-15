class Solution {
public:
    bool recursion(string s, string t, int i, int j) {
        if(i==0){
            return true;
        }
        if(j==0){
            return false;
        }

        if(s[i-1]==t[j-1]){
            return recursion(s, t, i-1, j-1)||recursion(s, t, i, j-1);
        }
        return recursion(s, t, i, j-1);
    }

    
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        return recursion(s, t, n, m);
    }
};