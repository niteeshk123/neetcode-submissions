class Solution {
public:
    int recursion(vector<int> &nums, int i, int prev_i){
        if(i==nums.size()){
            return 0;
        }
        int include = 0;
        if(prev_i==-1 || nums[i]>nums[prev_i]){
            include = 1+recursion(nums, i+1, i);
        }

        int exclude = recursion(nums, i+1, prev_i);

        return max(include, exclude);

    }
    int lengthOfLIS(vector<int>& nums) {
        return recursion(nums, 0, -1);
    }
};
