class Solution {
public:
    int recursion(vector<int> &nums, int i, int prev){
        if(i==nums.size()){
            return 0;
        }
        int include = 0;
        if(nums[i]>prev){
            include = 1+recursion(nums, i+1, nums[i]);
        }

        int exclude = recursion(nums, i+1, prev);

        return max(include, exclude);

    }
    int lengthOfLIS(vector<int>& nums) {
        return recursion(nums, 0, INT_MIN);
    }
};
