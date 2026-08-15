class Solution {
public:
    int kadanes(vector<int> &nums){
        int max_ending_here=nums[0];
        int min_ending_here=nums[0];

        int res = max_ending_here;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(max_ending_here, min_ending_here);
            }

            max_ending_here = max(nums[i], max_ending_here*nums[i]);
            min_ending_here = min(nums[i], min_ending_here*nums[i]);

            res = max(res, max_ending_here);
        }

        return res;

    }

    int maxProduct(vector<int>& nums) {
        return kadanes(nums);
    }
    int maxProduct_prefix_suffic(vector<int>& nums) {
        int prefix_prod = 1;
        int suffix_prod = 1;
        int res = INT_MIN;
        for(int i=0; i<nums.size();i++){
            prefix_prod *= nums[i];
            suffix_prod *= nums[nums.size()-1-i];
            res = max(res, max(prefix_prod, suffix_prod));
            if(prefix_prod==0){
                prefix_prod=1;
            }
            if(suffix_prod==0){
                suffix_prod=1;
            }
        }
        return res;
    }
};
