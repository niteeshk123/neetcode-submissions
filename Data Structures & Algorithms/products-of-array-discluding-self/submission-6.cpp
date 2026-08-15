class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_cnt = 0;
        int prod = 1;
        int n = nums.size();
        vector<int> res(n, 0);
        for(auto num: nums){
            if(num==0){
                zero_cnt++;
            } else {
                prod=prod*num;
            }
        }

        if(zero_cnt>=2){
            return res;
        }

        if(zero_cnt == 1){
            for(int i=0; i<n; i++){
                if(nums[i]==0){
                    res[i] = prod;
                    return res;
                }
            }
        }

        for(int i=0; i<n; i++){
            res[i] = prod/nums[i];
        }

        return res;
    }
};
