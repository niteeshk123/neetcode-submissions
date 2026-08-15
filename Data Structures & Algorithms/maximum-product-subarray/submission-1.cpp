class Solution {
public:
    int maxProduct(vector<int>& nums) {
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
