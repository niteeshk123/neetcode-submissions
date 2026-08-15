class Solution {
public:
    int bottom_up_lcs(string text1, string text2){
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<n+1;i++){
            for(int j=1; j<m+1;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];

    }

    int top_down_memo(string text1, string text2, int i1, int i2, vector<vector<int>> &dp){
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }

        if(i1>=text1.size()){
            dp[i1][i2] = 0;
        }

        else if(i2>=text2.size()){
            dp[i1][i2] = 0;
        }

        else if(text1[i1]==text2[i2]){
            dp[i1][i2] = 1 + top_down_memo(text1, text2, i1+1, i2+1, dp);
        }
        else{
            dp[i1][i2] = max(top_down_memo(text1, text2, i1+1, i2, dp), top_down_memo(text1, text2, i1, i2+1, dp));
        }
        return dp[i1][i2];
    }
    int lcs(string text1, string text2,int i1, int i2){
        if(i1>=text1.size()){
            return 0;
        }
        if(i2>=text2.size()){
            return 0 ;
        }

        if(text1[i1]==text2[i2]){
            return 1+lcs(text1, text2, i1+1, i2+1); 
        }
        return  max(lcs(text1, text2, i1, i2+1), lcs(text1, text2, i1+1, i2));

    }
    int longestCommonSubsequence(string text1, string text2) {
        // return lcs(text1, text2, 0, 0);
        return bottom_up_lcs(text1, text2);

        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        top_down_memo(text1, text2, 0, 0, dp);
    }
};
