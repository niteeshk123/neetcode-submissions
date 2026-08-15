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

    int top_down(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1));
        for(int i=0;i<n+1;i++){
            dp[i][0] = 0;
        }

        for(int i=0;i<amount+1; i++){
            dp[0][i] = 1e9;
        }

        for(int i=1; i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(j-coins[i-1]>=0){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        // int res = recursion(coins, amount, coins.size());
        // vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        // int res = memoization(coins, amount, coins.size(), dp);
        int res = top_down(coins, amount);
        if(res==1e9){
            return -1;
        }
        return res;
    }
};
