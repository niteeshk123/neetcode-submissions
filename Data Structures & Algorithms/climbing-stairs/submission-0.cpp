class Solution {
public:
    int recursion(int s){
        if(s<0){
            return 0;
        }
        else if(s==0){
            return 1;
        }

        return recursion(s-1)+recursion(s-2);
    }

    int memo(int s, vector<int>&dp){
        if(s<0){
            return 0;
        }
        if(dp[s]!=-1){
            return dp[s];
        }
        if(s==0){
            dp[s]=1;
            return dp[s];
        }

        dp[s] = memo(s-1, dp)+memo(s-2, dp);

        return dp[s];
    }
    int climbStairs(int n) {
        // return recursion(n);
        vector<int> dp(n+1, -1);
        return memo(n, dp);
    }
};
