class Solution {
public:
    int recursion(string s, int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(n==1){
            if(s[n-1]=='0'){
                return 0;
            }
            else{
                return 1;
            }
        }

        int one = 0;
        int two = 0;
        if(s[n-1]!='0'){
            one = recursion(s, n-1);
        }

        if(s[n-2]!='0' && s[n-1]>'0' && s[n-1]<'7'){
            two = recursion(s, n-2);
        }

        return one+two;
    }

    int memoization(string s, int n, vector<int> &dp){
        if(dp[n]!=-1){
            return dp[n];
        }

        if(n==0){
            dp[n]=1;
            return dp[n];
        }

        if(n==1){
            if(s[n-1]=='0'){
                dp[n] = 0;
                return dp[n];
            }
            else{
                dp[n] = 1;
                return dp[n];
            }
        }

        int one=0;
        int two = 0;
        if(s[n-1]!='0'){
            one = memoization(s, n-1, dp);
        }

        if(s[n-2]=='1' || (s[n-2]=='2' && s[n-1]>='0' && s[n-1]<'7')){
            two = memoization(s, n-2, dp);
        }
        dp[n] = one+two;
        return dp[n];
    }
    int numDecodings(string s) {
        // return recursion(s, s.size());
        vector<int> dp(s.size()+1, -1);
        return memoization(s, s.size(), dp);
    }
};
