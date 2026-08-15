class Solution {
public:
    int recursion(vector<int>& coins, int amount, int n){
        if(n<=0){
            return 1e9;
        }

        if(amount<=0){
            return 0;
        }

        if(amount-coins[n-1]>=0){
            return min(1+recursion(coins, amount-coins[n-1], n),recursion(coins, amount, n-1));
        }
        return recursion(coins, amount, n-1);
    }

    int memoization(vector<int>& coins, int amount, int n, vector<vector<int>> &dp){
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }

        if(n<=0){
            dp[n][amount] = 1e9;
            return dp[n][amount];
        }

        if(amount<=0){
            dp[n][amount] = 0;
            return dp[n][amount];
        }

        if(amount-coins[n-1]>=0){
            dp[n][amount] = min(1+memoization(coins, amount-coins[n-1],n,dp), memoization(coins, amount, n-1, dp));
        }
        else{
            dp[n][amount] = memoization(coins, amount, n-1, dp);
        }
        return dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int res = recursion(coins, amount, coins.size());
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        int res = memoization(coins, amount, coins.size(), dp);
        if(res==1e9){
            return -1;
        }
        return res;
    }
};
