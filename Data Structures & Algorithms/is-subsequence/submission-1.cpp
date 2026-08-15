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

    int topDown(string s, string t, int i, int j, vector<vector<int>> &dp) {
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==0){
            dp[i][j] = 1;
            return 1;
        }
        if(j==0){
            dp[i][j] = 0;
            return dp[i][j];
        }
        if(s[i-1] == t[j-1]){
            dp[i][j] = topDown(s, t, i-1, j-1, dp) || topDown(s,t, i, j-1, dp);
        } else {
            dp[i][j] = topDown(s,t, i, j-1, dp);
        }
        return dp[i][j];
    }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        // return recursion(s, t, n, m);
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return bool(topDown(s,t,n,m,dp));
    }
};