class Solution {
public:
    int recursion(vector<int> &nums, int h, bool nth_looted, vector<int> &dp) {
        if(h<0){
            return 0;
        }
        if(dp[h]!=-1){
            return dp[h];
        }
        if(h==0 && nth_looted){
            dp[h]=0;
            return dp[h];
        }
        // printf("h=%d and nums[h]=%d\n",h, nums[h]);
        dp[h] = max(nums[h]+recursion(nums, h-2, nth_looted, dp), recursion(nums, h-1, nth_looted, dp));
        return dp[h];
    }
    int rob(vector<int>& nums) {
        int l = nums.size();
        vector<int> dp(l, -1);
        int n1 = nums[l-1]+recursion(nums, l-3, true, dp);
        // printf("---------------------------------\n");
        vector<int> dp1(l, -1);
        int n2 = recursion(nums, l-2, false, dp1);
        return max(n1, n2);
        // return max(nums[l-1]+recursion(nums, l-3, true), recursion(nums, l-2, false));
    }
};
