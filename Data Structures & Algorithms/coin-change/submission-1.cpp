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
    int coinChange(vector<int>& coins, int amount) {
        int res = recursion(coins, amount, coins.size());

        if(res==1e9){
            return -1;
        }
        return res;
    }
};
