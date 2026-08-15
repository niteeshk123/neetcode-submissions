class Solution {
public:
    int recursion(vector<int>& nums, vector<int>& dp, int h){
        if(h<0){
            return 0;
        }
        if(dp[h]!=-1){
            return dp[h];
        }
        if(h==0){
            dp[h] = nums[0];
        }
        dp[h] = max(nums[h]+recursion(nums, dp, h-2), recursion(nums, dp, h-1));
        return dp[h];
    }
    int rob(vector<int>& nums) {
        int l = nums.size();
        vector<int> dp(l, -1);
        return recursion(nums, dp, l-1);
    }
};
