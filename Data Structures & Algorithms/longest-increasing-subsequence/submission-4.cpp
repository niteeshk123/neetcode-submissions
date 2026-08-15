class Solution {
public:
    int recursion(vector<int>& nums, int i, int prev_i,vector<vector<int>> &dp ){
        int n = nums.size();
        if(i>=n){
            return 0;
        }

        if(dp[i][prev_i+1]!=-1){
            return dp[i][prev_i+1];
        }
        int exc = recursion(nums, i+1, prev_i, dp);
        int inc = 0;
        if(prev_i==-1 || nums[i]>nums[prev_i]){
            inc = 1+recursion(nums, i+1, i, dp);
        }
        dp[i][prev_i+1] = max(inc, exc);
        return dp[i][prev_i+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recursion(nums,0, -1, dp);
    }
};
